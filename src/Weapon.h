#ifndef WEAPON_H
#define WEAPON_H

#include "GameObject.h"


class Weapon : public GameObject
{
  public:
    Weapon( Game* owner, GameObject* body );
    virtual ~Weapon();
    virtual void initialize() = 0;
    virtual void handleEvent( SDL_Event* event ) = 0;
    virtual void update( int msTimeStep ) = 0;
    virtual void draw( SDL_Surface* screen ) = 0;
    virtual void fire() = 0;
  protected:
    GameObject* _body;
    int _lastShot;
    int _firingSpeed;
    bool _triggerPulled;
  private:
};

#endif // WEAPON_H
