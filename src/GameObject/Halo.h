// ##### Halo #####
// The bastard circle around the ship.

#include "GameObject.h"
#include "PlayerShip.h"
#include "../Attribute/attributes.h"

class Halo:
  public GameObject,
  public Positionable,
  public Visable,
  public Collidable
{

private:
  double _radius;
  double _width;

public:

  Halo() {
    _width = 2;
  }
  
  ~Halo() {
  }
  
  void setRadius(double radius) {
    _radius = radius;
  }
  
  double getRadius() {
    return _radius;
  }
  
  virtual void draw() {
    // how get surface? from visable somehow
    Draw_FillCircle(surface, _radius, _radius, _radius, 0xFFFFFF);
    Draw_FillCircle(surface, _radius, _radius, _radius - _width, 0x000000);
  }
  
};