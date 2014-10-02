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
#import "WordTest+enhanced.h"

@implementation SpellingTest (enhanced)


/*///////////////////////////////////////////////////////////////////////////////////
 Accessors
 ///////////////////////////////////////////////////////////////////////////////////*/
- (NSDate *) dayAt {
    return [self dateAtBeginningOfDayForDate:self.endedAt];
}


/*///////////////////////////////////////////////////////////////////////////////////
 Constructors
 ///////////////////////////////////////////////////////////////////////////////////*/

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



/*///////////////////////////////////////////////////////////////////////////////////
 Lifecycle
 ///////////////////////////////////////////////////////////////////////////////////*/
/*
-(void) awakeFromFetch {
    self.dayAt = [self dateAtBeginningOfDayForDate:self.endedAt];
}
*/
/*///////////////////////////////////////////////////////////////////////////////////
 Date Utilities
 ///////////////////////////////////////////////////////////////////////////////////*/

- (NSDate *)dateAtBeginningOfDayForDate:(NSDate *)inputDate {
    // Use the user's current calendar and time zone
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSTimeZone *timeZone = [NSTimeZone systemTimeZone];
    [calendar setTimeZone:timeZone];
    
    // Selectively convert the date components (year, month, day) of the input date
    NSDateComponents *dateComps = [calendar components:NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit fromDate:inputDate];
    
    // Set the time components manually
    [dateComps setHour:0];
    [dateComps setMinute:0];
    [dateComps setSecond:0];
    
    // Convert back
    NSDate *beginningOfDay = [calendar dateFromComponents:dateComps];
    return beginningOfDay;
}


/*///////////////////////////////////////////////////////////////////////////////////
 Level & Result Utilities
 ///////////////////////////////////////////////////////////////////////////////////*/


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
            break;
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




- (void) setSpellingTestResult {
    
    int nbWord=0;
    int nbWordTestPassed=0;
    
    for (WordTest *wordTest in self.wordTests) {
        nbWord++;
        if ([wordTest.result intValue] == wordTestResultPass ) {
            nbWordTestPassed ++;
        }
    }
    int rate = (int) ceilf((nbWordTestPassed/nbWord)*100);
    spellingTestResult result;
    if (rate >=90) {
        result = spellingTestResultA;
    } else if (rate >=75) {
        result = spellingTestResultB;
    } else if (rate >=50) {
        result = spellingTestResultC;
    } else {
        result = spellingTestResultD;
    }
    self.result = [NSNumber numberWithInt:result];
}

- (NSString *) getSpellingTestResult {
    switch ([self.result intValue]) {
        case spellingTestResultA:
            return @"ResultA";
            break;
            
        case spellingTestResultB:
            return @"ResultB";
            break;
            
        case spellingTestResultC:
            return @"ResultC";
            break;
            
        case spellingTestResultD:
            return @"ResultD";
            break;
        default:
            return @"";
            break;
    }
    
}

- (NSString *) getSpellingTestLevel {
    switch ([self.level intValue]) {
        case spellingTestLevelEasy:
            return @"levelEasy";
            break;
            
        case spellingTestLevelMedium:
            return @"levelMedium";
            break;
            
        case spellingTestLevelHard:
            return @"levelHard";
            break;
            
        default:
            return @"";
            break;
    }
    
}
@end
