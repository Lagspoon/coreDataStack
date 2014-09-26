//
//  Kid+enhanced.m
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 25/09/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import "Kid+enhanced.h"

@implementation Kid (enhanced)


- (NSManagedObject *) kidInManagedObjectContext:(NSManagedObjectContext *) MOC {
    NSFetchRequest *fetchRequest = [NSFetchRequest fetchRequestWithEntityName:@"Kid"];
    NSPredicate *predicate = [NSPredicate predicateWithFormat:@"name like %@",self.name];
    [fetchRequest setPredicate:predicate];

    NSError *error;
    NSArray *arrayResult = [MOC executeFetchRequest:fetchRequest error:&error];

    if ([arrayResult count] == 1) {
        return [arrayResult firstObject];
    } else {
        return nil;
    }
}

@end
