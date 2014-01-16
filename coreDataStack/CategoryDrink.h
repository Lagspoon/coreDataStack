//
//  CategoryDrink.h
//  menu2Read
//
//  Created by Olivier Delecueillerie on 13/01/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface CategoryDrink : NSManagedObject

@property (nonatomic, retain) NSDate * createdAt;
@property (nonatomic, retain) NSData * image;
@property (nonatomic, retain) NSString * label;
@property (nonatomic, retain) NSString * objectId;
@property (nonatomic, retain) NSString * rank;
@property (nonatomic, retain) NSString * syncStatus;
@property (nonatomic, retain) NSData * thumbnail;
@property (nonatomic, retain) NSDate * updatedAt;
@property (nonatomic, retain) NSData * watermark;

@end
