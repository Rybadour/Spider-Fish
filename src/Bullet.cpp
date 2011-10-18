#include <string>
#include <cmath>

#include "SDL.h"

#include "Bullet.h"
#include "SpiderFish.h"
#include "Game.h"

Bullet::Bullet( Game* owner, SDL_Surface* image, int x, int y, int vx, int vy ):
  PhysicalEntity( owner,image,0,0,x,y )
{
  setVeloX(vx);
  setVeloY(vy);
}

Bullet::~Bullet()
{
}

void Bullet::draw( SDL_Surface* screen )
{
  PhysicalEntity::draw(screen);
}

void Bullet::handleEvent( SDL_Event* event )
{

}

void Bullet::update( int msTimeStep )
{
  PhysicalEntity::update(msTimeStep);
}
