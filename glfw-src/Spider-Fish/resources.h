//
//  Resources.h
//  Spider-Fish
//
//  Created by Jeffrey Drake on 11-09-24.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//
//  Resources.h is meant to provide for a platform independent way of
//  finding resources. 
//  Must be linked with source that provides these functions

#ifndef Spider_Fish_Resources_h
#define Spider_Fish_Resources_h

#ifdef CPLUSPLUS
#error Must be compiled for C++
#endif

std::string resourcePathFor(const std::string &name);

#endif
