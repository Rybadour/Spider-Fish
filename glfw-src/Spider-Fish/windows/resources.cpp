//
//  resources.cpp
//  Spider-Fish
//
//  Created by Jeffrey Drake on 11-09-24.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//
// Dummy version mostly right now

#include <string>
#include <iostream>

#include "../resources.h"

std::string resourcePathFor(const std::string &name) 
{	// change this path - can't find the api for current path of executable running
	const std::string prepName = "c:\\Users\\drakej\\source\\build-Spider-Fish\\resources\\" + name;
	
	return prepName;
}
