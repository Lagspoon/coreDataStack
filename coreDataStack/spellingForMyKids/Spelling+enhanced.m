//
//  Spelling+enhanced.m
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 26/09/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import "Spelling+enhanced.h"
#import "SpellingTest+enhanced.h"

@implementation Spelling (enhanced)

- (NSManagedObject *) spellingInManagedObjectContext:(NSManagedObjectContext *) MOC {
    NSFetchRequest *fetchRequest = [NSFetchRequest fetchRequestWithEntityName:@"Spelling"];
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

- (spellingTestMedal) spellingMedalFor:(Kid *)kid {
    NSSet *setSpellingTest = self.spellingTests;
    NSPredicate *predicateKid = [NSPredicate predicateWithFormat:@"kid == %@", kid];
    [setSpellingTest filteredSetUsingPredicate:predicateKid];
    NSArray *sortDescriptors = [NSArray arrayWithObject:[NSSortDescriptor sortDescriptorWithKey:@"endedAt" ascending:NO]];
    NSArray *arraySorted = [[setSpellingTest allObjects] sortedArrayUsingDescriptors:sortDescriptors];
    
    SpellingTest *lastTest = [arraySorted firstObject];
    return [lastTest spellingTestMedal];
}

@end
