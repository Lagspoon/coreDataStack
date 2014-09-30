//
//  SpellingTest.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 29/09/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Kid, Spelling, WordTest;

@interface SpellingTest : NSManagedObject

@property (nonatomic, retain) NSDate * endedAt;
@property (nonatomic, retain) NSNumber * level;
@property (nonatomic, retain) NSNumber * result;
@property (nonatomic, retain) NSDate * startedAt;
@property (nonatomic, retain) Kid *kid;
@property (nonatomic, retain) Spelling *spelling;
@property (nonatomic, retain) NSSet *wordTests;
@end

@interface SpellingTest (CoreDataGeneratedAccessors)

- (void)addWordTestsObject:(WordTest *)value;
- (void)removeWordTestsObject:(WordTest *)value;
- (void)addWordTests:(NSSet *)values;
- (void)removeWordTests:(NSSet *)values;

@end
