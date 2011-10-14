// SDL
#include "SDL.h"
#include "SDL_image.h"

// Game
#include "SpiderFish.h"
#include "Sprite.h"


Sprite::Sprite(uint id, SpriteManager* spriteManager, SDL_Surface* image)
  : _id(id),
    spriteManager(spriteManager),
    _image(image),
    x(0),
    y(0)
{
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
