//
//  Spelling+enhanced.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 26/09/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import "Spelling.h"
#import "SpellingTest+enhanced.h"


@interface Spelling (enhanced)

- (Spelling *) spellingInManagedObjectContext:(NSManagedObjectContext *) MOC;
- (spellingTestMedal) spellingMedalFor:(Kid *)kid;

@end
