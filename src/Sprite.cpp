#include "Sprite.h"

// SDL
#ifdef __APPLE__
#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#else
#include "SDL.h"
#include "SDL_image.h"
#endif

// C++

// Engine


Sprite::Sprite(uint id, SpriteManager* spriteManager, SDL_Surface* image)
{
    this->_id = id;
	this->spriteManager = spriteManager;
	this->_image = image;

	this->x = 0;
	this->y = 0;
}

void Sprite::draw(SDL_Surface* screen)
{
	if (_image != NULL)
	{
		SDL_Rect offset;
		offset.x = x;
		offset.y = y;

		SDL_BlitSurface(_image, NULL, screen, &offset);
	}
}

Sprite::~Sprite()
{
}