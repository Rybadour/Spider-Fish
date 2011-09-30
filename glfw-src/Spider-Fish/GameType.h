//
//  Game.h
//  Spider-Fish
//
//  Created by Jeffrey Drake on 11-09-28.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef Spider_Fish_Game_h
#define Spider_Fish_Game_h


class GameType {
public: 
	virtual bool setup() = 0;
	virtual bool loop() = 0;
    
    virtual void reshape(int width, int height) = 0;
	virtual void key(int k, int action) = 0;
};


#endif
