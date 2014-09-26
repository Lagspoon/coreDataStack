//
//  Kid+enhanced.h
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 25/09/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import "Kid.h"

@interface Kid (enhanced)

- (Kid *) kidInManagedObjectContext:(NSManagedObjectContext *) MOC;

@end
