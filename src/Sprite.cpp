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
<<<<<<< HEAD
    this->_id = id;
	this->spriteManager = spriteManager;
	this->_image = image;
=======
  this->id_ = id;
  this->spriteManager = spriteManager;
  this->_image = image;
>>>>>>> aff7312b3e1d020279d95ded9f5ebcb58d411942

  this->x = 0;
  this->y = 0;
}

void Sprite::draw(SDL_Surface* screen)
{
<<<<<<< HEAD
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
=======
  if (_image != NULL)
  {

    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface(_image, NULL, screen, &offset);
  }
}
>>>>>>> aff7312b3e1d020279d95ded9f5ebcb58d411942
