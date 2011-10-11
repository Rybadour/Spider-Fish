// C++
#include <assert.h>

// Engine
#include "CollisionManager.h"
#include "BruteForceSpace.h"

CollisionManager::CollisionList CollisionManager::getCollisions(PhysicalEntity &target) const {
	
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

void CollisionManager::addEntity(PhysicalEntity &entity) {
	getGroupSpace(entity.getGroup()).addEntity(entity);
}

void CollisionManager::removeEntity(PhysicalEntity &entity) {
	getGroupSpace(entity.getGroup()).removeEntity(entity);
}

void CollisionManager::useSpaceForGroup(unsigned int group, CollisionSpace *space) {
	
	// transfer entities from old to new space
	// transferSpace(getGroupSpace(group), *space);
	
	// discard old space and assign the new one
	_spaces[group] = space;

	// TODO: who is responsible for freeing the old space?

};

CollisionSpace &CollisionManager::getGroupSpace(unsigned int group) {

	// look for the space
	auto spaceIt = _spaces.find(group);

	CollisionSpace *space;

	// if no space exists for the group, default to BruteForceSpaces
	if (spaceIt == _spaces.end()) {
		space = new BruteForceSpace();
		_spaces.insert(spaces_pair_t(group, space));
	}
	else {
		space = spaceIt->second;
	}

	return *space;

};

void CollisionManager::transferSpace(CollisionSpace &oldSpace, CollisionSpace &newSpace) {
	assert(false && "Space transferring not yet implemented");
}