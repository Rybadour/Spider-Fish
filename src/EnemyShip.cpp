#include "EnemyShip.h"
#include "EnemyPeeShooter.h"

EnemyShip::EnemyShip(Game* owner,int x,int y):
  Ship(owner,
       owner->imageManager.createImage(img_resource("enemy.png")),
       x,y)
{
  _weapon = new EnemyPeeShooter(owner, this);
  setVeloY(100);
}

EnemyShip::~EnemyShip()
{
}

void EnemyShip::handleEvent(SDL_Event* event)
{
  //stop propogation
}



