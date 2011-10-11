#include "SpiderFishGame.h"

#include "Ship.h"

SpiderFishGame::SpiderFishGame() 
  : Game("Spider-Fish", 600, 420)
{
    this->addGameObject(new Ship(this));
}

void SpiderFishGame::handleEvent(SDL_Event* event)
{
    // If the ESC key is pressed quit the game
    if (event->type == SDL_KEYUP)
    {
        if (event->key.keysym.sym == SDLK_ESCAPE)
            _quit = true;
    }
}
