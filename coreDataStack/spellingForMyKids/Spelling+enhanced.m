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

- (spellingMedal) spellingMedalFor:(Kid *)kid {

    spellingMedal medal = spellingMedalEmpty;
    NSSet *setSpellingTest = self.spellingTests;
    //NSNumber *numberResut = [NSNumber numberWithInt:spellingTestResultA];
    
    //NSPredicate *predicateSpellingTestResultA = [NSPredicate predicateWithFormat:@"result == %@", numberResut];
    NSPredicate *predicateKid = [NSPredicate predicateWithFormat:@"kid == %@", kid];
    //NSPredicate *compoundPredicate = [NSCompoundPredicate andPredicateWithSubpredicates:@[predicateKid,predicateSpellingTestResultA]];
    
    [setSpellingTest filteredSetUsingPredicate:predicateKid];
    NSArray *sortDescriptors = [NSArray arrayWithObject:[NSSortDescriptor sortDescriptorWithKey:@"endedAt" ascending:NO]];
    NSArray *arraySorted = [[setSpellingTest allObjects] sortedArrayUsingDescriptors:sortDescriptors];
    
    for (SpellingTest *test in arraySorted) {
        NSLog([test.endedAt description]);
        NSLog(@"%i",[arraySorted indexOfObject:test]);
        NSLog([test.spelling.name description]);
        NSLog([test.result description]);
        NSLog([test.level description]);
    }
    
    SpellingTest *lastTest = [arraySorted firstObject];
    SpellingTest *previousTest;
    if ([arraySorted count]>2) {
        previousTest =[arraySorted objectAtIndex:1];
    }
    

    //first we test if the last test exist, else all spelling will have a bronze medal
    if (!lastTest) {
        medal = spellingMedalEmpty;
    } else {
        switch ([lastTest nextSpellingTestLevel] ) {
            case spellingTestLevelEasy:
                medal = spellingMedalEmpty;
                break;
            
            case spellingTestLevelMedium:
                medal = spellingMedalBronze;
                break;
                
            case spellingTestLevelHard:{
                NSLog(@"previoustest level %i result %i", [previousTest.level intValue], [previousTest.result intValue]);
                if (([previousTest.level intValue] == spellingTestLevelHard)&&([previousTest.result intValue] == spellingTestResultA)) {
                    medal = spellingMedalGold;
                } else {
                    medal = spellingMedalSilver;
                }
                break;
            }

            default:
                medal = spellingMedalEmpty;
                break;
        }
    }
    return medal;
}

@end
