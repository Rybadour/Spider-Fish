#ifndef SPIDERFISHGAME_H
#define SPIDERFISHGAME_H

// SDL
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include "SDL.h"
#endif

// Engine
#include "Game.h"

class SpiderFishGame : public Game
{
    public:
        SpiderFishGame();

    protected:
        void handleEvent(SDL_Event* event);
};

#endif // SPIDERFISHGAME_H