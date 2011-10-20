#include <list>
#include <cmath>

#include "SDL.h"

#include "PlayerShip.h"
#include "Ship.h"
#include "SpiderFish.h"
#include "SingleShooter.h"

const float PlayerShip::SPEED = 200; // pixels/sec

PlayerShip::PlayerShip( Game* owner, int x, int y ):
  Ship( owner,
        owner->imageManager.createImage( img_resource( "ship.png" ) ),
        x, y
      ),
  _halo( owner, 100, x, y )
{
  _weapon = new SingleShooter( owner, this );
  _weaponList.push_back( _weapon );
}

PlayerShip::~PlayerShip()
{
  _weapon = NULL;
  std::list<Weapon*>::iterator it = _weaponList.begin();
  std::list<Weapon*>::iterator ie = _weaponList.end();
  for( ; it != ie; ++it )
  {
    delete( *it );
  }
}

void PlayerShip::draw( SDL_Surface* screen )
{
  Ship::draw( screen );
  _halo.draw( screen );
}

void PlayerShip::handleEvent( SDL_Event * event )
{
  Ship::handleEvent( event );
  _weapon->handleEvent( event );
  // Key Down events
  switch( event->type )
  {
    case SDL_KEYDOWN:
      switch( event->key.keysym.sym )
      {
        case SDLK_UP:    _veloY -= SPEED; break;
        case SDLK_DOWN:  _veloY += SPEED; break;
        case SDLK_RIGHT: _veloX += SPEED; break;
        case SDLK_LEFT:  _veloX -= SPEED; break;
        default: break;
      }
      break;
    case SDL_KEYUP:
      switch( event->key.keysym.sym )
      {
        case SDLK_UP:    _veloY += SPEED; break;
        case SDLK_DOWN:  _veloY -= SPEED; break;
        case SDLK_RIGHT: _veloX -= SPEED; break;
        case SDLK_LEFT:  _veloX += SPEED; break;
        default: break;
      }
      break;
    default:
      break;
  }
}

void PlayerShip::update( int msTimeStep )
{
  Ship::update( msTimeStep );
  _halo.update( msTimeStep );

  if( getLeft() < 0 )
    setX( getWidth() / 2 );
  else if( getRight() > _owner->width )
    setX( _owner->width - getWidth() / 2 );
  if( getTop() < 0 )
    setY( getHeight() / 2 );
  else if( getBottom() > _owner->height )
    setY( _owner->height - getHeight() / 2 );

  _halo.setX( getX() );
  _halo.setY( getY() );
}
