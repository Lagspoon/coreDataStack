//
//  SpellingTest+mode.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 19/09/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import "SpellingTest.h"

@interface SpellingTest (enhanced)

typedef enum spellingTestLevel
{
    spellingTestLevelEasy=0,
    spellingTestLevelMedium = 1,
    spellingTestLevelHard = 2
} spellingTestLevel;


typedef enum spellingTestResult {
    spellingTestResultA = 3,    //A  acquis
    spellingTestResultB = 2,    //EA en cours acquisition
    spellingTestResultC = 1,    //AR à revoir
    spellingTestResultD = 0     //NA non acquis
} spellingTestResult;

typedef enum spellingTestMedal {
    spellingTestMedalEmpty = 0,
    spellingTestMedalBronze = 1,
    spellingTestMedalSilver = 2,
    spellingTestMedalGold = 3
} spellingTestMedal;

@property (strong, nonatomic) NSDate *dayAt; //used for sections in table views

+ (SpellingTest *) spellingTestFor:(Kid *)kid spelling:(Spelling *)spelling;
- (spellingTestMedal) spellingTestMedal;
- (spellingTestLevel) nextSpellingTestLevel;
- (void) setSpellingTestResult;
- (NSString *) getSpellingTestResult;
- (NSString *) getSpellingTestLevel;

@end
