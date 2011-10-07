#ifndef BRUTE_FORCE_SPACE_H
#define BRUTE_FORCE_SPACE_H

// C++
#include <map>

// boost
#include <boost/iterator/iterator_facade.hpp>

// Engine
#include "PhysicalEntity.h"
#include "CollisionSpace.h"

/*
 *
 */
class BruteForceSpace: public CollisionSpace
{

public:

  // adds entity to the space
  virtual void addEntity(PhysicalEntity &entity);

  // removes entity from space
  virtual void removeEntity(PhysicalEntity &entity);
  
  // return true if entity is in this space
  virtual bool hasEntity(PhysicalEntity &entity) ;
  
  // returns an iterator pair on all entities in this space
  virtual std::pair<AnyForwardIterator<PhysicalEntity>, AnyForwardIterator<PhysicalEntity>> getEntities();

  // if a PhysicalEntity has changed, then this update method must be
  // called before getCandidates() with the changed entity. this allows
  // the collision space to recognize and account for the those changes.
  virtual void update(PhysicalEntity &entity);
  
  // assumes all entities in this space need to be reevaluated and does so.
  // this is equivalent to using update() on every entity.
  virtual void updateAll();

  // returns an iterator pair over the potential collisions against the 
  // entity given.
  virtual std::pair<AnyForwardIterator<PhysicalEntity>, AnyForwardIterator<PhysicalEntity>> 
    getCandidates(PhysicalEntity &target);

protected:

private:

  class CandidateIterator: public boost::iterator_facade<
	CandidateIterator
  , PhysicalEntity
  , boost::forward_traversal_tag
  >
  {
	friend BruteForceSpace;
  private:

	std::map<unsigned int, PhysicalEntity&>::iterator _it;

	CandidateIterator(std::map<unsigned int, PhysicalEntity&>::iterator &it) {
		_it = it;
	}

	friend class boost::iterator_core_access;

	void increment() {
		++_it;
	}

	bool equal(CandidateIterator const &other) const {
		return _it == other._it;
	}

	PhysicalEntity &dereference() const {
		return _it->second;
	}

  }; // end class CandidateIterator

  std::map<unsigned int, PhysicalEntity&> _entities;

};

#endif