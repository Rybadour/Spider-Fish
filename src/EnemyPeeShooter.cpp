#include "EnemyPeeShooter.h"
#include "OrbBullet.h"
#include "Game.h"
#include "Ship.h"
#include "Weapon.h"

EnemyPeeShooter::EnemyPeeShooter( Game* owner, Ship* body ):
  Weapon( owner, body )
{
  _firingSpeed = 1000;
}

EnemyPeeShooter::~EnemyPeeShooter()
{
  //dtor
}

void EnemyPeeShooter::update( int msTimeStep )
{
  _lastShot += msTimeStep;
  if ( _lastShot > _firingSpeed )
  {
    _lastShot -= _firingSpeed;
    fire();
  }
}

void EnemyPeeShooter::handleEvent(SDL_Event* event)
{

}

void EnemyPeeShooter::draw( SDL_Surface* screen )
{
  //hidden under the ship, so do nothing
}

void EnemyPeeShooter::fire()
{
  OrbBullet* ob = new OrbBullet( _owner, _body->getX(), _body->getY() ) ;
  ob->setVeloY(ob->getVeloY()*-1);
  _owner->addGameObject( ob );
}
