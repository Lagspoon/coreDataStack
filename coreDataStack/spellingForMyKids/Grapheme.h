//
//  Grapheme.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 08/09/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Phoneme, Word;

@interface Grapheme : NSManagedObject

@property (nonatomic, retain) NSString * letters;
@property (nonatomic, retain) Phoneme *phonem;
@property (nonatomic, retain) NSSet *words;
@end

@interface Grapheme (CoreDataGeneratedAccessors)

- (void)addWordsObject:(Word *)value;
- (void)removeWordsObject:(Word *)value;
- (void)addWords:(NSSet *)values;
- (void)removeWords:(NSSet *)values;

@end
