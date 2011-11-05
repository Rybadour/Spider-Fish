#ifndef ENEMYPEESHOOTER_H
#define ENEMYPEESHOOTER_H

#include "Weapon.h"


class EnemyPeeShooter : public Weapon
{
  public:
    EnemyPeeShooter( Game* owner, Ship* body );
    virtual ~EnemyPeeShooter();
    virtual void update(int msTimeStep);
    virtual void draw(SDL_Surface* screen);
    virtual void fire();
    virtual void handleEvent(SDL_Event* event);
  protected:
  private:
};

#endif // ENEMYPEESHOOTER_H
