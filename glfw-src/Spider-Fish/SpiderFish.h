//
//  SpiderFish.h
//  Spider-Fish
//
//  Created by Jeffrey Drake on 11-09-28.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef Spider_Fish_SpiderFish_h
#define Spider_Fish_SpiderFish_h

#include "Spider-Fish-Prefix.pch"

#include "resources.h"
#include "Shader.h"

#include "GameType.h"

#include "Ship.h"

#include "Shader.h"

using namespace std;



class SpiderFish : public GameType {
public:
    SpiderFish() { }
	bool setup();
	bool loop();
    
    void reshape(int width, int height);
	void key(int k, int action);
    void setView(float x1, float y1, float x2, float y2);
    void updateProjection();
private:
    Ship ship;
    array<float, 4> viewport;

};


#endif
