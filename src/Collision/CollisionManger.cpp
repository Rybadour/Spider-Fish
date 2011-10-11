// C++
#include <assert.h>

// Engine
#include "CollisionManager.h"

CollisionManager::CollisionList CollisionManager::getCollisions(PhysicalEntity const &target) const {
	
	// Iterators on candidate spaces

	auto getSpace = GetSpace();
	auto getCandidateList = GetCandidateList(target);
	auto groupMaskFilter = GroupMaskFilter(target.getGroupMask());

	auto candidateSpaceBeginIt = 
		AdaptedCandidateSpaceIterator_t(
		  CandidateSpaceIterator_t(
		    CandidateGroupIterator_t(groupMaskFilter, _spaces.begin(), _spaces.end()) // begin
		  , getSpace
		  )
	    , getCandidateList
		);

	auto candidateSpaceEndIt =
		AdaptedCandidateSpaceIterator_t(
		  CandidateSpaceIterator_t(
		    CandidateGroupIterator_t(groupMaskFilter, _spaces.end(), _spaces.end()) // end
		  , getSpace
		  )
	    , getCandidateList
		);

	// Iterators on all candidates
	auto allCandidatesBeginIt = AllCandidatesIterator_t(candidateSpaceBeginIt, candidateSpaceEndIt);
	auto allCandidatesEndIt = AllCandidatesIterator_t(candidateSpaceEndIt, candidateSpaceEndIt);
	
	// Iterators on all collisions
	auto collisionFilter = CollisionFilter(target);
	auto collisionBeginIt = CollisionIterator_t(
		collisionFilter, allCandidatesBeginIt, allCandidatesEndIt);
	auto collisionEndIt = CollisionIterator_t(
		collisionFilter, allCandidatesEndIt, allCandidatesEndIt);
	
	// CollisionList container
	auto collisionList = CollisionList(collisionBeginIt, collisionEndIt);

	return collisionList;
}

bool CollisionManager::areColliding(PhysicalEntity const &entityA, PhysicalEntity const &entityB) {
	return !(entityA.getRight() < entityB.getLeft() // A is left of B
		|| entityA.getLeft() > entityB.getRight()	// A is right of B
		|| entityA.getBottom() < entityB.getTop()	// A is above B
		|| entityA.getTop() > entityB.getBottom()	// A is below B
		);
}

void CollisionManager::addEntity(PhysicalEntity const &entity) const {
	getGroupSpace(entity.getGroup()).addEntity(entity);
}

void CollisionManager::removeEntity(PhysicalEntity const &entity) const {
	getGroupSpace(entity.getGroup()).removeEntity(entity);
}

void CollisionManager::useSpaceForGroup(const unsigned int group, CollisionSpace * const space) {

	// disallow overriding a space that already exists
	assert(_spaces.find(group) == _spaces.end());

	// assign this space to the group
	_spaces.insert(spaces_pair_t(group, space));

};

CollisionSpace &CollisionManager::getGroupSpace(const unsigned int group) const {

	// look for the space
	auto spaceIt = _spaces.find(group);

	// trying to get a group that doesn't exist is an error.
	// note to client: did you try to add an entity without
	// setting up the group with useSpaceForGroup() first?
	assert(spaceIt != _spaces.end());

	// return the space by reference
	return *(spaceIt->second);

};

void CollisionManager::transferSpace(CollisionSpace &oldSpace, CollisionSpace &newSpace) {
	assert(false && "Space transferring not yet implemented");
}

void CollisionManager::updateEntity(PhysicalEntity const &entity) const {
	getGroupSpace(entity.getGroup()).update(entity);
}

void CollisionManager::updateGroup(const unsigned int group) const {
	getGroupSpace(group).updateAll();
}

void CollisionManager::updateAll() const {

	auto it = _spaces.begin();
	auto end = _spaces.end();

	while (it != end) {
		it->second->updateAll();
		++it;
	}

}