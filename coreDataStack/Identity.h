//
//  Identity.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 28/12/2013.
//  Copyright (c) 2013 Olivier Delecueillerie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface Identity : NSManagedObject

@property (nonatomic, retain) NSString * about;
@property (nonatomic, retain) NSString * adress;
@property (nonatomic, retain) NSDate * createdAt;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSString * objectId;
@property (nonatomic, retain) NSString * phone;
@property (nonatomic, retain) NSString * syncStatus;
@property (nonatomic, retain) NSDate * updatedAt;

@end
