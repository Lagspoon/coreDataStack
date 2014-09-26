//
//  SpellingTest+mode.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 19/09/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import "SpellingTest.h"

@interface SpellingTest (mode)

typedef enum spellingTestLevel
{
    spellingTestLevelEasy=0,
    spellingTestLevelMedium = 1,
    spellingTestLevelHard = 2
} spellingTestLevel;


typedef enum spellingTestResult {
    spellingTestResultA = 0,    //A  acquis
    spellingTestResultB = 1,    //EA en cours acquisition
    spellingTestResultC = 2,    //AR à revoir
    spellingTestResultD = 3     //NA non acquis
} spellingTestResult;

- (spellingTestLevel) nextSpellingTestLevel;

@end
