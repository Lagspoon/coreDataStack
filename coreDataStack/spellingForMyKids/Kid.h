//
//  Kid.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 08/09/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Spelling, SpellingTest, Test, Word;

@interface Kid : NSManagedObject

@property (nonatomic, retain) NSNumber * age;
@property (nonatomic, retain) NSData * image;
@property (nonatomic, retain) NSNumber * level;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSNumber * schoolLevel;
@property (nonatomic, retain) NSSet *spellings;
@property (nonatomic, retain) SpellingTest *spellingTests;
@property (nonatomic, retain) NSSet *words;
@property (nonatomic, retain) NSSet *wordTests;
@end

@interface Kid (CoreDataGeneratedAccessors)

- (void)addSpellingsObject:(Spelling *)value;
- (void)removeSpellingsObject:(Spelling *)value;
- (void)addSpellings:(NSSet *)values;
- (void)removeSpellings:(NSSet *)values;

- (void)addWordsObject:(Word *)value;
- (void)removeWordsObject:(Word *)value;
- (void)addWords:(NSSet *)values;
- (void)removeWords:(NSSet *)values;

- (void)addWordTestsObject:(Test *)value;
- (void)removeWordTestsObject:(Test *)value;
- (void)addWordTests:(NSSet *)values;
- (void)removeWordTests:(NSSet *)values;

@end