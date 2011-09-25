#include "CollisionManager.h"

bool CollisionManager::_checkIfColliding(PhysicalEntity &entityA,
  PhysicalEntity &entityB) {
  
  if (entityA.getRight() <= entityB.getLeft()) return false;
  if (entityA.getLeft() >= entityB.getRight()) return false;
  if (entityA.getBottom() <= entityB.getTop()) return false;
  if (entityA.getTop() >= entityB.getBottom()) return false;
  
  return true;

};