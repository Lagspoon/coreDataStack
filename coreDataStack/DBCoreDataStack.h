//
//  DBCoreDataStack.h
//  EditionMenu
//
//  Created by Olivier Delecueillerie on 05/11/2013.
//  Copyright (c) 2013 Olivier Delecueillerie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@interface DBCoreDataStack : NSObject


@property (nonatomic, strong, readonly) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, strong, readonly) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, strong, readonly) NSPersistentStoreCoordinator *persistentStoreCoordinator;


typedef enum datamodel datamodel;
enum datamodel
{
    data = 0,
    webservicesSync = 1,
};

+ (DBCoreDataStack *) sharedInstanceFor:(datamodel) datamodel;

- (NSURL *)applicationDocumentsDirectory;
- (void)saveContext;

@end
