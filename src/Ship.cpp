// c++
#include <cmath>
#include <list>

// SDL
#include "SDL.h"
#include "SDL_gfxPrimitives.h"

// Engine
#include "SpiderFish.h"
#include "Game.h"
#include "SingleShooter.h"
#include "Ship.h"

Ship::Ship( Game* owner , SDL_Surface* img, int x, int y ) :
  PhysicalEntity(
    owner ,
    img,
    0, 0, x, y ),
  _weapon( NULL )
{
}

Ship::~Ship()
{
}

void Ship::draw( SDL_Surface * surface )
{
  PhysicalEntity::draw( surface );
}

void Ship::handleEvent( SDL_Event * event )
{
  if( _weapon != NULL )
    _weapon->handleEvent( event );
}

void Ship::update( int msTimeStep )
{
  if( _weapon != NULL )
    _weapon->update( msTimeStep );
  PhysicalEntity::update( msTimeStep );
}

