//
//  SpellingTest+mode.m
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 19/09/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import "SpellingTest+mode.h"

@implementation SpellingTest (mode)

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

@end
