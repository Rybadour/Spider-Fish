// C++
#include <map>

// Engine
#include "BruteForceSpace.h"
#include "PhysicalEntity.h"
#include "../Util/AnyForwardIterator.h"

// adds entity to the space
void BruteForceSpace::addEntity(PhysicalEntity &entity) {
  _entities.insert(std::pair<unsigned int, PhysicalEntity&>(entity.getId(), entity));
}

// removes entity from space
void BruteForceSpace::removeEntity(PhysicalEntity &entity) {
  _entities.erase(entity.getId());
}

// return true if entity is in this space
bool BruteForceSpace::hasEntity(PhysicalEntity &entity) {
  return _entities.find(entity.getId()) != _entities.end();
}

// returns an iterator pair on all entities in this space
std::pair<AnyForwardIterator<PhysicalEntity>, AnyForwardIterator<PhysicalEntity> >
  BruteForceSpace::getEntities()
{
  return std::pair<AnyForwardIterator<PhysicalEntity>, AnyForwardIterator<PhysicalEntity> >(
    AnyForwardIterator<PhysicalEntity>(CandidateIterator(_entities.begin())),
    AnyForwardIterator<PhysicalEntity>(CandidateIterator(_entities.end()))
  );
}

// if a PhysicalEntity has changed, then this update method must be
// called before getCandidates() with the changed entity. this allows
// the collision space to recognize and account for the those changes.
void BruteForceSpace::update(PhysicalEntity &entity) {
  // no update is done in a brute force space
}

// assumes all entities in this space need to be reevaluated and does so.
// this is equivalent to using update() on every entity.
void BruteForceSpace::updateAll() {
  // no update is done in a brute force space
}

// returns an iterator pair over the potential collisions against the 
// entity given.
std::pair<AnyForwardIterator<PhysicalEntity>, AnyForwardIterator<PhysicalEntity> > 
  BruteForceSpace::getCandidates(PhysicalEntity &target)
{
  // all entities are candidates in brute force space
  return getEntities();
}