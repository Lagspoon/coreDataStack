//
//  Kid+newKid.m
//  coreDataStack
//
//  Created by Olivier Delecueillerie on 21/08/2014.
//  Copyright (c) 2014 Olivier Delecueillerie. All rights reserved.
//

#import "Kid+newKid.h"

@implementation Kid (newKid)

+ (Kid *) createANewKid {
    Kid *newKid = [[Kid alloc] init];
    
    newKid.name = @"create a new kid";
    newKid.image = UIImagePNGRepresentation([UIImage imageNamed:@"add_user.png"]);

    return newKid;
    }

@end
