#include "Weapon.h"

Weapon::Weapon( Game* owner, Ship* body ):
  GameObject( owner ),
  _body( body ),
  _lastShot( 0 ),
  _firingSpeed( 0 ),
  _triggerPulled( false )
{
  //ctor
}

Weapon::~Weapon()
{
  //dtor
}
