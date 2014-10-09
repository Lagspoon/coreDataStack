//
//  WordTest.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 02/10/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Kid, Spelling, SpellingTest, Word;

@interface WordTest : NSManagedObject

@property (nonatomic, retain) NSDate * endedAt;
@property (nonatomic, retain) NSString * input;
@property (nonatomic, retain) NSDate * startedAt;
@property (nonatomic, retain) NSNumber * result;
@property (nonatomic, retain) Kid *kid;
@property (nonatomic, retain) Spelling *spelling;
@property (nonatomic, retain) SpellingTest *spellingTest;
@property (nonatomic, retain) Word *word;

@end
