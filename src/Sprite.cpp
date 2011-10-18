// SDL
#include "SDL.h"
#include "SDL_image.h"

// Game
#include "SpiderFish.h"
#include "Sprite.h"


Sprite::Sprite( SDL_Surface* image ):
  _image( image )
{
}

void Sprite::draw( SDL_Surface* screen, int x, int y )
{
  if( _image != NULL )
  {
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( _image, NULL, screen, &offset );
  }
}

