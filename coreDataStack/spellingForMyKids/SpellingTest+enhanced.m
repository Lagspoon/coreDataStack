//
//  SpellingTest+mode.m
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 19/09/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import "SpellingTest+mode.h"
#import "Kid+enhanced.h"
#import "Spelling+enhanced.h"

@implementation SpellingTest (enhanced)

- (spellingTestLevel) upwardSpellingTestLevel {
    switch ([self.level intValue]) {
        case spellingTestLevelEasy:
            return spellingTestLevelMedium;
            break;
        case spellingTestLevelMedium:
            return spellingTestLevelHard;
            break;
        default:
            return spellingTestLevelHard;
            break;
    }
}


- (spellingTestLevel) downwardSpellingTestLevel {
    switch ([self.level intValue]) {
        case spellingTestLevelHard:
            return spellingTestLevelMedium;
            break;
        case spellingTestLevelMedium:
            return spellingTestLevelEasy;
        default:
            return spellingTestLevelEasy;
            break;
    }
}


- (spellingTestLevel) nextSpellingTestLevel {
    if (!self.result) {
        return spellingTestLevelEasy;
    } else {
        switch ([self.result intValue]) {
            case spellingTestResultA:
                return [self upwardSpellingTestLevel];
                break;
                
            case spellingTestResultD:
                return [self downwardSpellingTestLevel];
                break;
                
            default:
                return [self.level intValue];
                break;
        }
    }
}

+ (SpellingTest *) spellingTestFor:(Kid *)kid spelling:(Spelling *)spelling {
    NSManagedObjectContext *MOC = [kid managedObjectContext];
    if (!(MOC == [spelling managedObjectContext])) {
        NSLog(@"error in spellingTest creation because managedObjectContext of relationship object are different");
        spelling = [spelling spellingInManagedObjectContext:MOC ];
    }
    SpellingTest *spellingTest = [NSEntityDescription insertNewObjectForEntityForName:@"SpellingTest" inManagedObjectContext:MOC];
    spellingTest.kid = kid;
    spellingTest.spelling = spelling;
    
    
    //spellingTest.level = [
    
    NSMutableSet *spellingTests = [NSMutableSet setWithSet:spelling.spellingTests];
    for (SpellingTest *spellingTestEach in spellingTests) {
        if (!(spellingTestEach.kid == kid)) {
            [spellingTests removeObject:spellingTestEach];
        }
    }
    
    NSArray *sortDescriptors = [NSArray arrayWithObject:[NSSortDescriptor sortDescriptorWithKey:@"endedAt" ascending:YES]];
    NSArray *arraySorted = [[spellingTests allObjects] sortedArrayUsingDescriptors:sortDescriptors];
    SpellingTest *spellingTestLast = [arraySorted lastObject];
    
    spellingTest.level = [NSNumber numberWithInt:[spellingTestLast nextSpellingTestLevel]];
    
    return spellingTest;
}

@end
