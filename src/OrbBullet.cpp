#include "OrbBullet.h"
#include "Bullet.h"
#include "SpiderFish.h"
#include "Game.h"

OrbBullet::OrbBullet(Game* owner,int x,int y):
  Bullet(owner,owner->imageManager.createImage(img_resource("bullet.png")),x,y,0,-350)
{
  //ctor
}

OrbBullet::~OrbBullet()
{
  //dtor
}
