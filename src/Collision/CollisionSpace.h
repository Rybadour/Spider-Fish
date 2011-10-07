#ifndef COLLISION_SPACE_H
#define COLLISION_SPACE_H

// Engine
#include "PhysicalEntity.h"
#include "../Util/AnyForwardIterator.h"

class CollisionSpace {

public:

  // adds entity to the space
  virtual void addEntity(PhysicalEntity &entity) = 0;

  // removes entity from space
  virtual void removeEntity(PhysicalEntity &entity) = 0;
  
  // return true if entity is in this space
  virtual bool hasEntity(PhysicalEntity &entity) = 0;
  
  // returns an iterator pair on all entities in this space
  virtual std::pair<AnyForwardIterator<PhysicalEntity>, AnyForwardIterator<PhysicalEntity>> getEntities() = 0;

  // if a PhysicalEntity has changed, then this update method must be
  // called before getCandidates() with the changed entity. this allows
  // the collision space to recognize and account for the those changes.
  virtual void update(PhysicalEntity &entity) = 0;
  
  // assumes all entities in this space need to be reevaluated and does so.
  // this is equivalent to using update() on every entity.
  virtual void updateAll() = 0;

  // returns an iterator pair over the potential collisions against the 
  // entity given.
  virtual std::pair<AnyForwardIterator<PhysicalEntity>, AnyForwardIterator<PhysicalEntity>> 
    getCandidates(PhysicalEntity &target) = 0;

protected:

private:

};

#endif