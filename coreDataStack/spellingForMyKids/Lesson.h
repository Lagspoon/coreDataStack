//
//  Lesson.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 02/10/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Phoneme, Spelling;

@interface Lesson : NSManagedObject

@property (nonatomic, retain) NSData * explanation;
@property (nonatomic, retain) NSNumber * type;
@property (nonatomic, retain) NSNumber * language;
@property (nonatomic, retain) NSSet *phonems;
@property (nonatomic, retain) NSSet *spellings;
@end

@interface Lesson (CoreDataGeneratedAccessors)

- (void)addPhonemsObject:(Phoneme *)value;
- (void)removePhonemsObject:(Phoneme *)value;
- (void)addPhonems:(NSSet *)values;
- (void)removePhonems:(NSSet *)values;

- (void)addSpellingsObject:(Spelling *)value;
- (void)removeSpellingsObject:(Spelling *)value;
- (void)addSpellings:(NSSet *)values;
- (void)removeSpellings:(NSSet *)values;

@end
