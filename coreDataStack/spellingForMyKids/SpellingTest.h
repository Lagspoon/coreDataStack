//
//  SpellingTest.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 08/09/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Kid, Spelling, Test;

@interface SpellingTest : NSManagedObject

@property (nonatomic, retain) NSDate * endedAt;
@property (nonatomic, retain) NSNumber * mode;
@property (nonatomic, retain) NSNumber * points;
@property (nonatomic, retain) NSDate * startedAt;
@property (nonatomic, retain) Kid *kid;
@property (nonatomic, retain) Spelling *spelling;
@property (nonatomic, retain) NSSet *wordTests;
@end

@interface SpellingTest (CoreDataGeneratedAccessors)

- (void)addWordTestsObject:(Test *)value;
- (void)removeWordTestsObject:(Test *)value;
- (void)addWordTests:(NSSet *)values;
- (void)removeWordTests:(NSSet *)values;

@end
