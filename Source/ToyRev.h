//
//  ToyRev.h
//  ToyCouch
//
//  Created by Jens Alfke on 12/2/11.
//  Copyright (c) 2011 Couchbase, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
@class ToyDocument;


/** Stores information about a revision -- its docID, revID, and whether it's deleted. It can also store the document contents (mutably). */
@interface ToyRev : NSObject
{
    NSString* _docID, *_revID;
    BOOL _deleted;
    ToyDocument* _document;
}

- (id) initWithDocID: (NSString*)docID 
               revID: (NSString*)revID 
             deleted: (BOOL)deleted;

@property (readonly) NSString* docID;
@property (readonly) NSString* revID;
@property (readonly) BOOL deleted;

@property (retain) ToyDocument* document;

@end



@interface ToyRevSet : NSObject <NSFastEnumeration>
{
    @private
    NSMutableSet* _revs;
}

@property (readonly) NSUInteger count;
- (void) addRev: (ToyRev*)rev;
- (void) removeRev: (ToyRev*)rev;
- (ToyRev*) revWithDocID: (NSString*)docID revID: (NSString*)revID;

- (NSEnumerator*) objectEnumerator;

@property (readonly) NSArray* allDocIDs;

@end
