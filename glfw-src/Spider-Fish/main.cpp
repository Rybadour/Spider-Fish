//
//  main.cpp
//  Spider-Fish
//
//  Created by Jeffrey Drake on 11-09-28.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "SpiderFish.h"

GameType *game = NULL;

void GLFWCALL reshape( int width, int height );

void GLFWCALL reshape( int width, int height ) 
{
    if (game) game->reshape(width, height);
    
}

void GLFWCALL key( int k, int action );

void GLFWCALL key( int k, int action )
{
    if (game) game->key(k, action);
    
}



void RenderInfo()
{
	std::cout << "OpenGL Rendering Info" << std::endl;
	
	if (glGetString(GL_VENDOR) == NULL) 
	{
		std::cout << "No Vendor String" << std::endl;
		return;
	}
	
	std::cout << "Vendor:" << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Shading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl << std::endl;
}



int main() 
{
	game = new SpiderFish(); // global now for glfw...
	
	if (game->setup()) {
        glfwSetWindowSizeCallback(reshape);
        glfwSetKeyCallback(key);

        while (game->loop());
    }
    
    glfwTerminate();
    
    return 0;
}
