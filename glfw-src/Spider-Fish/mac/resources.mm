//
//  resources.mm
//  Spider-Fish
//
//  Created by Jeffrey Drake on 11-09-24.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#include <string>
#include <iostream>

#include "../resources.h"

std::string resourcePathFor(const std::string &name) 
{
    NSBundle *bundle = [NSBundle mainBundle];

    NSString *location = [bundle pathForResource: [NSString stringWithCString: name.c_str() encoding: NSUTF8StringEncoding] 
                                          ofType: nil];

    const char *utf8location = [location UTF8String];
    
    return std::string(utf8location, [location length]);
}
