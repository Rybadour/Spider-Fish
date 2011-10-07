// C++
#include <cassert>

// Engine
#include "CollisionManager.h"
#include "BruteForceSpace.h"

/*
 * CollisionManager
 */

CollisionManager::CollisionManager() {
	
}

void CollisionManager::addEntity(PhysicalEntity &entity) {
	getGroupSpace(entity.getGroup()).addEntity(entity);
}

void CollisionManager::removeEntity(PhysicalEntity &entity) {
	getGroupSpace(entity.getGroup()).removeEntity(entity);
}

CollisionManager::CollisionIterator CollisionManager::getCollisions(PhysicalEntity &entity) {
	return CollisionManager::CollisionIterator(*this, entity);
};

void CollisionManager::useSpaceForGroup(unsigned int group, CollisionSpace *space) {
	
	// transfer entities from old to new space
	transferSpace(getGroupSpace(group), *space);
	
	// discard old space and assign the new one
	_spaces[group] = space;

};

CollisionSpace &CollisionManager::getGroupSpace(unsigned int group) {

	// look for the space
	std::map<int, CollisionSpace*>::iterator spaceIt = _spaces.find(group);

	CollisionSpace *space;

	// if no space exists for the group, default to BruteForceSpaces
	if (spaceIt == _spaces.end()) {
		space = new BruteForceSpace();
		_spaces.insert(std::pair<unsigned int, CollisionSpace*>(group, space));
	}
	else {
		space = spaceIt->second;
	}

	return *space;

};

void CollisionManager::transferSpace(CollisionSpace &oldSpace, CollisionSpace &newSpace) {
	assert(false && "Space transferring not yet implemented");
}

bool CollisionManager::_checkIfColliding(PhysicalEntity &entityA, PhysicalEntity &entityB) {
	return !(  entityA.getRight() < entityB.getLeft() // A is left of B
			|| entityA.getLeft() > entityB.getRight() // A is right of B
			|| entityA.getBottom() < entityB.getTop() // A is above B
			|| entityA.getTop() > entityB.getBottom() // A is below B
			);
}

/*
 * GroupMask
 */

CollisionManager::GroupMask::GroupMask(int groupMask) {
	_groupMask = groupMask;
}

bool CollisionManager::GroupMask::operator()(std::pair<unsigned int, CollisionSpace *> group) {
	return (_groupMask & group.first) > 0;
}

/*
 * CollisionTest
 */

CollisionManager::CollisionTest::CollisionTest(PhysicalEntity &target)
	: _target(target) {
	_target = target;
}

bool CollisionManager::CollisionTest::operator()(PhysicalEntity &other) {
	return CollisionManager::_checkIfColliding(_target, other);
}

/*
 * CollisionIterator
 */

/*CollisionManager::CollisionIterator::CollisionIterator(CollisionManager &manager, PhysicalEntity &target) {
			
	// setup predicates
	GroupMask predGroupMask = GroupMask(target.getGroupMask());
	CollisionTest predCollisionTest = CollisionTest(target);

	// setup group iterator
	CandidateGroupIterator candGroupIt = CandidateGroupIterator(predGroupMask, manager._spaces.begin(), manager._spaces.end());
	CandidateGroupIterator candGroupItEnd = CandidateGroupIterator(predGroupMask, manager._spaces.end(), manager._spaces.end());

	// setup candidate iterator
	CandidateIterator candidateIt = CandidateIterator(target, _candGroupIt, _candGroupItEnd);

	// setup collision iterator
	_collisionIt = CollisionIterator_(predCollisionTest, candidateIt);

}*/