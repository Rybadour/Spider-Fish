#ifndef SDL_GAME_ENGINE__SPRITE_H
#define SDL_GAME_ENGINE__SPRITE_H

// SDL
#include "SDL.h"

// Engine
#include "SpiderFish.h"

class SpriteManager; // Forward declaration, acts like including the header

class Sprite
{
  public:
    int x;
    int y;
    int w;
    int h;

    Sprite(SDL_Surface* image);
    void draw(SDL_Surface* screen);

  private:
    SDL_Surface* _image;
};

#endif
