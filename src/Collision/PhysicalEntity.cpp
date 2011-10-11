#include "PhysicalEntity.h"

#include <vector>

// initialize the first id to 0
unsigned int PhysicalEntity::_nextId = 0;

PhysicalEntity::PhysicalEntity(unsigned int group, unsigned int groupMask, 
	unsigned int width, unsigned int height, unsigned int x, unsigned int y)
{
	// setup basic attributes
	setGroup(group);
	setGroupMask(groupMask);
	setWidth(width);
	setHeight(height);
	setX(x);
	setY(y);

	// assign the next id in sequence
	setId(PhysicalEntity::_nextId);
	++PhysicalEntity::_nextId;
}

// returns entity id
unsigned int PhysicalEntity::getId() const {
	return _id;
}

void PhysicalEntity::setId(unsigned int id) {
	_id = id;
}
  
// returns left-most x
int PhysicalEntity::getLeft() const {
	return _x;
}

// returns right-most x
int PhysicalEntity::getRight() const {
	return _x + _width;
}

// returns top-most y
int PhysicalEntity::getTop() const {
	return _y;
}

// returns bottom-most y
int PhysicalEntity::getBottom() const {
	return _y + _height;
}

// width of entity
unsigned int PhysicalEntity::getWidth() const {
	return _width;
}

void PhysicalEntity::setWidth(unsigned int width) {
	_width = width;
}

// height of entity
unsigned int PhysicalEntity::getHeight() const {
	return _height;
}

void PhysicalEntity::setHeight(unsigned int height) {
	_height = height;
}

// top left x position
int PhysicalEntity::getX() const {
	return _x;
}

void PhysicalEntity::setX(int x) {
	_x = x;
}

// top left y position
int PhysicalEntity::getY() const {
	return _y;
}

void PhysicalEntity::setY(int y) {
	_y = y;
}

// group
unsigned int PhysicalEntity::getGroup() const {
	return _group;
}

void PhysicalEntity::setGroup(unsigned int group) {
	_group = group;
}

// groupMask
unsigned int PhysicalEntity::getGroupMask() const {
	return _groupMask;
}

void PhysicalEntity::setGroupMask(unsigned int groupMask) {
	_groupMask = groupMask;
}

bool PhysicalEntity::getCollidesWithGroup(unsigned int group) const {
	return (_groupMask & group) > 0;
}