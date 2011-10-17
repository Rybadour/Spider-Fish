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

// Constant
const float Ship::SPEED = 500; // pixels/sec

Ship::Ship( Game* owner, Uint32 haloColour ) :
  GameObject( owner ),
  _sprite( owner->imageManager.createImage( img_resource( "ship.png" ) ) ),
  _veloX( 0 ),
  _veloY( 0 ),
  _overflowX( 0 ),
  _overflowY( 0 ),
  _haloRad( 100 ),
  _haloColour( haloColour ),
  _activeWeapon( NULL )
{
}

Ship::~Ship()
{
  std::list<Weapon*>::iterator it = _weaponList.begin();
  std::list<Weapon*>::iterator ie = _weaponList.end();
  for (; it != ie; ++it)
  {
    delete (*it);
  }
}

void Ship::draw( SDL_Surface* surface )
{
  aacircleColor( surface, _sprite.x, _sprite.y, _haloRad, _haloColour );
  aacircleColor( surface, _sprite.x, _sprite.y, _haloRad + 1, ( _haloColour & 0xFFFFFF00 ) | 0xFFFFFF99 );
  aacircleColor( surface, _sprite.x, _sprite.y, _haloRad - 1, ( _haloColour & 0xFFFFFF00 ) | 0xFFFFFF99 );
  _sprite.draw( surface );

}

void Ship::initialize()
{
  _sprite.x = 200;
  _sprite.y = 100;
  _activeWeapon = new SingleShooter(_owner,this);
  _weaponList.push_back( _activeWeapon );
}

void Ship::handleEvent( SDL_Event* event )
{
  _activeWeapon->handleEvent( event );
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

void Ship::update( int msTimeStep )
{
  _activeWeapon->update(msTimeStep);
  //increase size of rin
  this->_haloRad += msTimeStep / 100.0;

  // TODO: Refactored to something nicer
  _overflowX += _veloX * ( msTimeStep / 1000.0 );
  _overflowY += _veloY * ( msTimeStep / 1000.0 );

  if( _overflowX >= 1 || _overflowX <= -1 )
  {
    _sprite.x += floor( _overflowX );
    _overflowX -= floor( _overflowX );
  }
  if( _overflowY >= 1  || _overflowY <= -1 )
  {
    _sprite.y += floor( _overflowY );
    _overflowY -= floor( _overflowY );
  }
  if( _sprite.x - _sprite.w / 2 < 0 )
    _sprite.x = _sprite.w / 2;
  else if( _sprite.x + _sprite.w / 2 > _owner->width )
    _sprite.x = _owner->width - _sprite.w / 2;
  if( _sprite.y - _sprite.w / 2 < 0 )
    _sprite.y = _sprite.w / 2;
  else if( _sprite.y + _sprite.h / 2 > _owner->height )
    _sprite.y = _owner->height - _sprite.h / 2;
}

int Ship::getX()
{
  return _sprite.x;
}

int Ship::getY()
{
  return _sprite.y;
}

