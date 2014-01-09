//
//  CategoryDrink.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 28/12/2013.
//  Copyright (c) 2013 Olivier Delecueillerie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Drink;

@interface CategoryDrink : NSManagedObject

@property (nonatomic, retain) NSDate * createdAt;
@property (nonatomic, retain) NSData * image;
@property (nonatomic, retain) NSString * label;
@property (nonatomic, retain) NSString * objectId;
@property (nonatomic, retain) NSNumber * rank;
@property (nonatomic, retain) NSString * syncStatus;
@property (nonatomic, retain) NSData * thumbnail;
@property (nonatomic, retain) NSDate * updatedAt;
@property (nonatomic, retain) NSData * watermark;
@property (nonatomic, retain) NSSet *drinks;
@end

@interface CategoryDrink (CoreDataGeneratedAccessors)

- (void)addDrinksObject:(Drink *)value;
- (void)removeDrinksObject:(Drink *)value;
- (void)addDrinks:(NSSet *)values;
- (void)removeDrinks:(NSSet *)values;

@end
