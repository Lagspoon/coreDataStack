//
//  Test.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 08/09/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Kid, Spelling, SpellingTest, Word;

@interface Test : NSManagedObject

@property (nonatomic, retain) NSDate * endedAt;
@property (nonatomic, retain) NSString * input;
@property (nonatomic, retain) NSNumber * mode;
@property (nonatomic, retain) NSNumber * result;
@property (nonatomic, retain) NSDate * startedAt;
@property (nonatomic, retain) Kid *kid;
@property (nonatomic, retain) Spelling *spelling;
@property (nonatomic, retain) SpellingTest *spellingTest;
@property (nonatomic, retain) Word *word;

@end
