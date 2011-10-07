#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

// C++
#include <map>

// boost
#include <boost/iterator/filter_iterator.hpp>
#include <boost/iterator/iterator_facade.hpp>

// Engine
#include "PhysicalEntity.h"
#include "CollisionSpace.h"
#include "../Util/IteratorIterator.h"

class CollisionManager {

private:

	// predicate to filter groups
	class GroupMask {
	public:
		GroupMask() {} // again how does one avoid these?
		GroupMask(int groupMask);
		bool operator()(std::pair<unsigned int, CollisionSpace *> group);
	private:
		int _groupMask;
	};

	// predicate to filter collisions
	class CollisionTest {
	public:
		CollisionTest(PhysicalEntity &target);
		bool operator()(PhysicalEntity &other);
	private:
		PhysicalEntity &_target;
	};

	typedef std::map<int, CollisionSpace*>::iterator SpaceIterator;
	typedef boost::filter_iterator<GroupMask, SpaceIterator> CandidateGroupIterator;
  
  class CandidateIterator: public IteratorIterator<
      CandidateIterator
    , CandidateGroupIterator
    , AnyForwardIterator<PhysicalEntity>
    , PhysicalEntity
    >
  {

  public:

    CandidateIterator(PhysicalEntity &target, CandidateGroupIterator &begin, CandidateGroupIterator &end)
      : IteratorIterator(begin, end)
      , _target(target) {
    }
  
  protected:
 
	// TODO: this makes two pairs

	  friend IteratorIterator; // TODO not exactly sure why IteratorIterator needs this
	  // in order to see subItBegin() and subItEnd()

    AnyForwardIterator<PhysicalEntity> subItBegin() {
		return getIt()->second->getCandidates(_target).first;
    }
 
    AnyForwardIterator<PhysicalEntity> subItEnd() {
      return getIt()->second->getCandidates(_target).second;
    }
  
  private:
  
    PhysicalEntity &_target;
  
  }; // end class CandidateIterator

  // allow CandidateIterator to see _spaces
  friend CandidateIterator;
  
public:

	class CollisionIterator: public boost::filter_iterator<
	  CollisionTest
	, CandidateIterator
	> {
		friend CollisionManager;
	public:
	protected:
	private:

		// constructor
		CollisionIterator(CollisionManager &manager, PhysicalEntity &target) :
		 boost::filter_iterator<CollisionTest, CandidateIterator>(
		  CollisionTest(target)
		  , CandidateIterator(
		   target
		   , CandidateGroupIterator(GroupMask(target.getGroupMask()), manager._spaces.begin())
		   , CandidateGroupIterator(GroupMask(target.getGroupMask()), manager._spaces.end())
		   )
		  , CandidateIterator(
		   target
		   , CandidateGroupIterator(GroupMask(target.getGroupMask()), manager._spaces.end())
		   , CandidateGroupIterator(GroupMask(target.getGroupMask()), manager._spaces.end())
		   )
		  )
		 {
		 }

	}; // end class CollisionIterator
	friend CollisionIterator;

	// empty constructor
	CollisionManager();

	// adds an entity to the collision manager
	void addEntity(PhysicalEntity &entity);

	// removes an entity from the collision manager
	void removeEntity(PhysicalEntity &entity);

	// returns an iterator on collisions against the argument entity
	CollisionIterator getCollisions(PhysicalEntity &entity);

	// tells the collision manager to use a specific space type for
	// a given entity group. useful for optimization. if no space is
	// given, BruteForceSpace is used by default.
	void useSpaceForGroup(unsigned int group, CollisionSpace *space);

protected:

private:
  
	// map of spaces used for each group
	std::map<int, CollisionSpace*> _spaces;

	// returns the space the group is using. this will force a default space
	// if one is not already given.
	CollisionSpace &getGroupSpace(unsigned int group);

	// copies the entity pointers from the old space to the new space
	void transferSpace(CollisionSpace &oldSpace, CollisionSpace &newSpace);

	// used to determine if two entities are colliding
	static bool _checkIfColliding(PhysicalEntity &entityA, PhysicalEntity &entityB);

};

#endif