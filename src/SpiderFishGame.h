#ifndef SPIDERFISHGAME_H
#define SPIDERFISHGAME_H

// SDL
#include "SDL.h"

// Engine
#include "SpiderFish.h"
#include "Game.h"

class SpiderFishGame : public Game
{
  public:
    SpiderFishGame();

  protected:
    virtual void handleEvent(SDL_Event*);
};

#endif // SPIDERFISHGAME_H
