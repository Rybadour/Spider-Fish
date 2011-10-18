#include "SpiderFish.h"
#include "SpiderFishGame.h"
#include "PlayerShip.h"
#include "Game.h"

SpiderFishGame::SpiderFishGame() :
  Game( "Spider-Fish", 600, 420 )
{
  this->addGameObject( new PlayerShip( this, 200, 200 ) );
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
