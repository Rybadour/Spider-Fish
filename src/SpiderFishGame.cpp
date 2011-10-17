#include "SpiderFish.h"
#include "SpiderFishGame.h"
#include "Ship.h"
#include "Game.h"

SpiderFishGame::SpiderFishGame() :
  Game( "Spider-Fish", 600, 420 )
{
  this->addGameObject(new Ship(this,0xFFFFFFFF ));
}

void SpiderFishGame::handleEvent( SDL_Event* event )
{
  switch( event->type )
  {
    case SDL_KEYUP:
      switch( event->key.keysym.sym )
      {
        case SDLK_ESCAPE:
          _quit = true;
          break;
        default: break;
      }
      break;
    default: break;
  }
  Game::handleEvent( event );
}
