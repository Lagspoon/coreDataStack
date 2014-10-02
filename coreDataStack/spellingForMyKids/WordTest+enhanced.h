//
//  WordTest+scoring.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 19/09/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import "WordTest.h"

@interface WordTest (enhanced)


typedef enum wordTestMistake {
    wordTestMistakeAccent = 3,
    wordTestMistakeLexical = 2,
    wordTestMistakeHomophone = 1, 
} wordTestMistake;


typedef enum wordTestResult {
    wordTestResultPass = 1,
    wordTestResultFail = 0
} wordTestResult;

@end
