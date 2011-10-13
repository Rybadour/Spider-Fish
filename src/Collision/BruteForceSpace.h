#ifndef BRUTE_FORCE_SPACE_H
#define BRUTE_FORCE_SPACE_H

// C++
#include <map>

// boost
#include <boost/iterator/transform_iterator.hpp>

// Engine
#include "PhysicalEntity.h"
#include "CollisionSpace.h"

/* BruteForceSpace
 * The dumbest but simplest of collision spaces. Assumes that all entities
 * are candidates to collide with the target.
 */
class BruteForceSpace: public CollisionSpace
{

public:

  // adds entity to the space
  void addEntity(PhysicalEntity const &entity);

  // removes entity from space
  void removeEntity(PhysicalEntity const &entity);
  
  // return true if entity is in this space
  bool hasEntity(PhysicalEntity const &entity) const;
  
  // returns an iterator pair on all entities in this space
  PhysicalEntityList getEntities() const;

  // if a PhysicalEntity has changed, then this update method must be
  // called before getCandidates() with the changed entity. this allows
  // the collision space to recognize and account for the those changes.
  void update(PhysicalEntity const &entity);
  
  // assumes all entities in this space need to be reevaluated and does so.
  // this is equivalent to using update() on every entity.
  void updateAll();

  // returns an iterator pair over the potential collisions against the 
  // entity given.
  CandidateList getCandidates(PhysicalEntity const &target) const;

protected:

private:

  // convience
  typedef std::map<unsigned int, PhysicalEntity const &> map_t;
  typedef map_t::const_iterator map_it_t;
  typedef map_t::value_type map_pair_t;

  // function object to extract entity from map pair.
  // used in transform iterator.
  class GetEntityFromPair {
  public:
	  
	  typedef PhysicalEntity const & result_type;

	  PhysicalEntity const &operator() (map_pair_t const &pair) const {
		  return pair.second;
	  }
  
  };

  typedef boost::transform_iterator<GetEntityFromPair, map_it_t>
	  EntityIterator;

  // storage for all entities in this space
  map_t _entities;

};

#endif