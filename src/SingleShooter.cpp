// c++
#include <cmath>

// SDL
#include "SDL.h"
#include "SDL_gfxPrimitives.h"

// Engine
#include "SpiderFish.h"
#include "Game.h"
#include "SingleShooter.h"
#include "OrbBullet.h"

// Constant

SingleShooter::SingleShooter( Game* owner, Ship* body ) :
  Weapon( owner, body )
{
  _firingSpeed = 200;
}

SingleShooter::~SingleShooter()
{
}

void SingleShooter::handleEvent( SDL_Event* event )
{
  switch( event->type )
  {
    case SDL_KEYDOWN:
      switch( event->key.keysym.sym )
      {
        case SDLK_SPACE:
          _triggerPulled = true;
        default:
          break;
      }
      break;
    case SDL_KEYUP:
      switch( event->key.keysym.sym )
      {
        case SDLK_SPACE:
          _triggerPulled = false;
        default:
          break;
      }
    default:
      break;
  }
}

void SingleShooter::update( int msTimeStep )
{
  _lastShot += msTimeStep;
  if( _triggerPulled )
  {
    if( _firingSpeed < _lastShot )
    {
      fire();

      _lastShot = _lastShot % _firingSpeed;
    }
  }
}

void SingleShooter::draw( SDL_Surface* screen )
{
}

void SingleShooter::fire()
{
  //_owner->addGameObject( new OrbBullet( _body->getX(), _body->getY() ) );
  _owner->addGameObject( new OrbBullet( _owner, _body->getX(), _body->getY() ) );
}
