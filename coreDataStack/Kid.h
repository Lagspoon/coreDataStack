//
//  Kid.h
//  spellingForMyKids
//
//  Created by Olivier Delecueillerie on 11/02/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Test;

@interface Kid : NSManagedObject

@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSData * image;
@property (nonatomic, retain) NSSet *test;
@end

@interface Kid (CoreDataGeneratedAccessors)

- (void)addTestObject:(Test *)value;
- (void)removeTestObject:(Test *)value;
- (void)addTest:(NSSet *)values;
- (void)removeTest:(NSSet *)values;

@end
