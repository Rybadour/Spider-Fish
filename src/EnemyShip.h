#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H

#include "Ship.h"


class EnemyShip : public Ship
{
  public:
    EnemyShip(Game* owner,int x,int y);
    virtual ~EnemyShip();
    virtual void handleEvent(SDL_Event* event);
  protected:
  private:
};

#endif // ENEMYSHIP_H
