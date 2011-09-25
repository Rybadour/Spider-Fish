#ifndef SPIDERFISHGAME_H
#define SPIDERFISHGAME_H

// SDL
#include "SDL.h"

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