#ifndef COLLISION_SPACE_H
#define COLLISION_SPACE_H

// Engine
#include "PhysicalEntity.h"
// #include "../Util/AnyForwardIterator.h"
#include "../Util/FauxContainer.h"

// becker's any_iterator
#include "../Util/any_iterator.hpp"

class CollisionSpace {

public:

  //typedef AnyForwardIterator<PhysicalEntity> Iterator;
  typedef IteratorTypeErasure::any_iterator<
	  PhysicalEntity const, std::forward_iterator_tag
    > Iterator;
  typedef FauxContainer<Iterator> PhysicalEntityList;
  typedef FauxContainer<Iterator> CandidateList;

  // adds entity to the space
  virtual void addEntity(PhysicalEntity const &entity) = 0;

  // removes entity from space
  virtual void removeEntity(PhysicalEntity const &entity) = 0;
  
  // return true if entity is in this space
  virtual bool hasEntity(PhysicalEntity const &entity) const = 0;
  
  // returns an iterator pair on all entities in this space
  virtual PhysicalEntityList getEntities() const = 0;

  // if a PhysicalEntity has changed, then this update method must be
  // called before getCandidates() with the changed entity. this allows
  // the collision space to recognize and account for the those changes.
  virtual void update(PhysicalEntity const &entity) = 0;
  
  // assumes all entities in this space need to be reevaluated and does so.
  // this is equivalent to using update() on every entity.
  virtual void updateAll() = 0;

  // returns an iterator pair over the potential collisions against the 
  // entity given.
  virtual CandidateList getCandidates(PhysicalEntity const &target) const = 0;

protected:

private:

};

#endif