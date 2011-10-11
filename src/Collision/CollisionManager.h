#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

// C++
#include <map>

// boost
#include <boost/iterator/filter_iterator.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <boost/iterator/transform_iterator.hpp>

// Engine
#include "PhysicalEntity.h"
#include "CollisionSpace.h"
#include "../Util/Iterator2D.h"
#include "../Util/FauxContainer.h"

class CollisionManager {
	
private:

	typedef std::map<const unsigned int, CollisionSpace * const> spaces_t;
	typedef spaces_t::const_iterator spaces_it_t;
	typedef spaces_t::value_type spaces_pair_t;

	// group -> space
	spaces_t _spaces;

	/* GetSpace function object
	 */
	class GetSpace {
	public:
		
		typedef CollisionSpace *result_type;
		
		CollisionSpace *operator ()(spaces_pair_t const &pair) const {
			return pair.second;
		}
	
	};

	/* GroupMaskFilter function object
	 */
	class GroupMaskFilter {
	public:

		GroupMaskFilter(GroupMaskFilter const &other) :
			_groupMask(other._groupMask) {
		}

		GroupMaskFilter(const unsigned int groupMask) :
			_groupMask(groupMask) {
		}

		bool operator ()(spaces_pair_t const &pair) {
			return (_groupMask & pair.first) > 0;
		}

	private:
		const unsigned int _groupMask;
	};

	/* GetCandidateList function object
	 */
	class GetCandidateList {
	public:

		GetCandidateList(GetCandidateList const &other) : 
			_target(other._target) { }

		// needed by boost to determine return type of the functor
		typedef CollisionSpace::CandidateList result_type;
		
		// basic constructor
		GetCandidateList(PhysicalEntity const &target) : _target(target)
		{ }
		
		CollisionSpace::CandidateList operator ()(CollisionSpace const* const space) const {
			return space->getCandidates(_target);
		}
	
	private:
		PhysicalEntity const &_target;
	};

	/* CollisionFilter function object
	 */
	class CollisionFilter {
	
	public:

		CollisionFilter(PhysicalEntity const &target) : _target(target)
		{ }

		CollisionFilter(CollisionFilter const &other) :
		_target(other._target) { }
		
		bool operator ()(PhysicalEntity const &other) const {
			return CollisionManager::areColliding(_target, other);
		}
	
	private:
		PhysicalEntity const &_target;
	};

	// iterator only over groups that the target collides with
	typedef boost::filter_iterator<GroupMaskFilter, spaces_it_t> CandidateGroupIterator_t;

	// iterator over just the spaces (discard group ids)
	typedef boost::transform_iterator<GetSpace, CandidateGroupIterator_t> CandidateSpaceIterator_t;

	// adapted to expose begin() and end() methods that access the iterators returned by
	// getCandidates(target) from the given space. this is required to be compliant with
	// Iterator2D.
	typedef boost::transform_iterator<GetCandidateList, CandidateSpaceIterator_t> AdaptedCandidateSpaceIterator_t;

	// Iterator over all possible PhysicalEntities the target can be
	// colliding with (candidates from all spaces).
	typedef Iterator2D<AdaptedCandidateSpaceIterator_t> AllCandidatesIterator_t;

	// CollisionIterator, iterates over all collisions against the target
	typedef boost::filter_iterator<CollisionFilter, AllCandidatesIterator_t> CollisionIterator_t;

	// CollisionList, container that holds the start and end iterators
	typedef FauxContainer<CollisionIterator_t> CollisionList_t;

public:

	// list container of all collisions against a target.
	typedef CollisionList_t CollisionList;

	CollisionList getCollisions(PhysicalEntity const &target) const;

	// adds an entity to the collision manager
	void addEntity(PhysicalEntity const &entity) const;

	// removes an entity from the collision manager
	void removeEntity(PhysicalEntity const &entity) const;

	// tells the collision manager to use a specific space type for
	// a given entity group. useful for collision optimization. if no space is
	// given, BruteForceSpace is used by default.
	void useSpaceForGroup(const unsigned int group, CollisionSpace * const space);

	// Notifies all CollisionSpaces of an update on this PhysicalEntity
	void updateEntity(PhysicalEntity const &entity) const;

	// Notifies the space of updates on all of its PhysicalEntities
	void updateGroup(const unsigned int group) const;

	// Notifies all spaces on updates of all PhyaicalEntities
	void updateAll() const;

	// tests if two PhysicalEntities are colliding.
	static bool areColliding(PhysicalEntity const &entityA, PhysicalEntity const &entityB);

protected:

private:

	// returns the space the group is using. this will force a default space
	// if one is not already given.
	CollisionSpace &getGroupSpace(const unsigned int group) const;

	// copies the entity pointers from the old space to the new space
	void transferSpace(CollisionSpace &oldSpace, CollisionSpace &newSpace);

};

#endif