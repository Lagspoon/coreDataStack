//
//  Spelling.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 27/09/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Kid, Lesson, SpellingTest, Word, WordTest;

@interface Spelling : NSManagedObject

@property (nonatomic, retain) NSString * explication;
@property (nonatomic, retain) NSNumber * level;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSSet *kids;
@property (nonatomic, retain) Lesson *lesson;
@property (nonatomic, retain) NSSet *spellingTests;
@property (nonatomic, retain) NSSet *words;
@property (nonatomic, retain) NSSet *wordTests;
@end

@interface Spelling (CoreDataGeneratedAccessors)

- (void)addKidsObject:(Kid *)value;
- (void)removeKidsObject:(Kid *)value;
- (void)addKids:(NSSet *)values;
- (void)removeKids:(NSSet *)values;

- (void)addSpellingTestsObject:(SpellingTest *)value;
- (void)removeSpellingTestsObject:(SpellingTest *)value;
- (void)addSpellingTests:(NSSet *)values;
- (void)removeSpellingTests:(NSSet *)values;

- (void)addWordsObject:(Word *)value;
- (void)removeWordsObject:(Word *)value;
- (void)addWords:(NSSet *)values;
- (void)removeWords:(NSSet *)values;

- (void)addWordTestsObject:(WordTest *)value;
- (void)removeWordTestsObject:(WordTest *)value;
- (void)addWordTests:(NSSet *)values;
- (void)removeWordTests:(NSSet *)values;

@end
