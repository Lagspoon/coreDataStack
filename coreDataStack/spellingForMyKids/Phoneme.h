//
//  Phoneme.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 02/10/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Lesson, Word;

@interface Phoneme : NSManagedObject

@property (nonatomic, retain) NSString * api;
@property (nonatomic, retain) NSData * audio;
@property (nonatomic, retain) NSString * type;
@property (nonatomic, retain) NSSet *words;
@property (nonatomic, retain) NSSet *lessons;
@end

@interface Phoneme (CoreDataGeneratedAccessors)

- (void)addWordsObject:(Word *)value;
- (void)removeWordsObject:(Word *)value;
- (void)addWords:(NSSet *)values;
- (void)removeWords:(NSSet *)values;

- (void)addLessonsObject:(Lesson *)value;
- (void)removeLessonsObject:(Lesson *)value;
- (void)addLessons:(NSSet *)values;
- (void)removeLessons:(NSSet *)values;

@end
