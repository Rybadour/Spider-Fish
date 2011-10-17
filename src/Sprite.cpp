// SDL
#include "SDL.h"
#include "SDL_image.h"

// Game
#include "SpiderFish.h"
#include "Sprite.h"


Sprite::Sprite( SDL_Surface* image ) :
  x( 0 ),
  y( 0 ),
  w( image->w ),
  h( image->h ),
  _image( image )

{
}

void Sprite::draw( SDL_Surface* screen )
{
  if( _image != NULL )
  {
    SDL_Rect offset;
    offset.x = x-w/2;
    offset.y = y-h/2;

    SDL_BlitSurface( _image, NULL, screen, &offset );
  }
}

