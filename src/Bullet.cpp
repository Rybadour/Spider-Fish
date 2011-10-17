#include <string>
#include <cmath>

#include "SDL.h"

#include "SpiderFish.h"
#include "Bullet.h"
#include "Sprite.h"

Bullet::Bullet( Game* owner, SDL_Surface* image, int x, int y, int vx, int vy ):
  GameObject( owner ),
  _sprite( image ),
  _veloX( vx ),
  _veloY( vy ),
  _overflowX( 0 ),
  _overflowY( 0 )
{
  _sprite.x = x;
  _sprite.y = y;
}

Bullet::~Bullet()
{
}

void Bullet::initialize()
{
}

void Bullet::draw( SDL_Surface* screen )
{
  _sprite.draw( screen );
}

void Bullet::handleEvent( SDL_Event* event )
{

}

void Bullet::update( int msTimeStep )
{
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
}
