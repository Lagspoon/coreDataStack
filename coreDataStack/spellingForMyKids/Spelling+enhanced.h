//
//  Spelling+enhanced.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 26/09/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import "Spelling.h"

@interface Spelling (enhanced)

typedef enum spellingMedal {
    spellingMedalEmpty = 0,
    spellingMedalBronze = 1,
    spellingMedalSilver = 2,
    spellingMedalGold = 3
} spellingMedal;


- (Spelling *) spellingInManagedObjectContext:(NSManagedObjectContext *) MOC;
- (spellingMedal) spellingMedalFor:(Kid *)kid;
@end
