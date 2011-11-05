#include <list>
#include <fstream>

#include "SDL.h"

#include "SpiderFish.h"
#include "SpiderFishGame.h"
#include "PlayerShip.h"
#include "Game.h"
#include "EnemyData.h"
#include "EnemyShip.h"

SpiderFishGame::SpiderFishGame() :
  Game( "Spider-Fish", 600, 420 )
{
  this->addGameObject( new PlayerShip( this, 200, 200 ) );
  loadEnemyList();
}

void SpiderFishGame::loadEnemyList()
{
  std::ifstream fin( lvl_resource( "level1.dat" ) );
  Uint32 time;
  int x;
  int type;
  while( fin >> type >> time >> x )
    _enemyList.push_back( EnemyData( type, time, x ) );
}

void SpiderFishGame::update( Uint32 msTimeStep )
{

  Uint32 gameTime = SDL_GetTicks();
  if( _enemyList.size() > 0 )
  {
    if( _enemyList.front().getTime() < gameTime )
    {
      EnemyData ed = _enemyList.front();
      _enemyList.pop_front();
      addGameObject( new EnemyShip( this, ed.getX(), -10 ) );
    }
  }
  Game::update( msTimeStep );
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
