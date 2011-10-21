#ifndef ORBBULLET_H
#define ORBBULLET_H

#include "Bullet.h"


class OrbBullet : public Bullet
{
  public:
    OrbBullet(Game* owner,int x,int y);
    virtual ~OrbBullet();
  protected:
  private:
};

#endif // ORBBULLET_H
