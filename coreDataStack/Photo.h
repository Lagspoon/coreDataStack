//
//  Photo.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 27/12/2013.
//  Copyright (c) 2013 Olivier Delecueillerie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface Photo : NSManagedObject

@property (nonatomic, retain) NSDate * createdAt;
@property (nonatomic, retain) NSData * image;
@property (nonatomic, retain) NSNumber * index;
@property (nonatomic, retain) NSString * objectId;
@property (nonatomic, retain) NSString * syncStatus;
@property (nonatomic, retain) NSString * title;
@property (nonatomic, retain) NSDate * updatedAt;
@property (nonatomic, retain) NSString * usedFor;

@end
