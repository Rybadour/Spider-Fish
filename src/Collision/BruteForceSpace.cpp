// C++
#include <map>

// Engine
#include "BruteForceSpace.h"
#include "PhysicalEntity.h"

// adds entity to the space
void BruteForceSpace::addEntity(PhysicalEntity const &entity) {
  _entities.insert(map_pair_t(entity.getId(), entity));
}

// removes entity from space
void BruteForceSpace::removeEntity(PhysicalEntity const &entity) {
  _entities.erase(entity.getId());
}

// return true if entity is in this space
bool BruteForceSpace::hasEntity(PhysicalEntity const &entity) const {
  return _entities.find(entity.getId()) != _entities.end();
}

// returns an iterator pair on all entities in this space
BruteForceSpace::PhysicalEntityList BruteForceSpace::getEntities() const
{
  return PhysicalEntityList(
    Iterator(
	  EntityIterator(_entities.begin(), GetEntityFromPair())
	)
  , Iterator(
      EntityIterator(_entities.end(), GetEntityFromPair())
	)
  );
}

// if a PhysicalEntity has changed, then this update method must be
// called before getCandidates() with the changed entity. this allows
// the collision space to recognize and account for the those changes.
void BruteForceSpace::update(PhysicalEntity const &entity) {
  // no update is done in a brute force space
}

// assumes all entities in this space need to be reevaluated and does so.
// this is equivalent to using update() on every entity.
void BruteForceSpace::updateAll() {
  // no update is done in a brute force space
}

// returns an iterator pair over the potential collisions against the 
// entity given.
BruteForceSpace::CandidateList BruteForceSpace::getCandidates(PhysicalEntity const &target) const
{
  // all entities are candidates in brute force space
  return CandidateList(
    Iterator(
	  EntityIterator(_entities.begin(), GetEntityFromPair())
	)
  , Iterator(
      EntityIterator(_entities.end(), GetEntityFromPair())
	)
  );
}