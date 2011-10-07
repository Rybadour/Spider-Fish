#include "PhysicalEntity.h"

#include <vector>

unsigned int PhysicalEntity::_nextId = 0;

PhysicalEntity::PhysicalEntity(unsigned int width, unsigned int height,
	unsigned int x, unsigned int y)
{
	_width = width;
	_height = height;
	_x = x;
	_y = y;
	_id = PhysicalEntity::_nextId;
	++PhysicalEntity::_nextId;
}

// returns entity id
unsigned int PhysicalEntity::getId() {
	return _id;
}
  
// returns left-most x
int PhysicalEntity::getLeft() {
	return _x;
}

// returns right-most x
int PhysicalEntity::getRight() {
	return _x + _width;
}

// returns top-most y
int PhysicalEntity::getTop() {
	return _y;
}

// returns bottom-most y
int PhysicalEntity::getBottom() {
	return _y + _height;
}

// width of entity
unsigned int PhysicalEntity::getWidth() {
	return _width;
}

void PhysicalEntity::setWidth(unsigned int width) {
	_width = width;
}

// height of entity
unsigned int PhysicalEntity::getHeight() {
	return _height;
}

void PhysicalEntity::setHeight(unsigned int height) {
	_height = height;
}

// top left x position
int PhysicalEntity::getX() {
	return _x;
}

void PhysicalEntity::setX(int x) {
	_x = x;
}

// top left y position
int PhysicalEntity::getY() {
	return _y;
}

void PhysicalEntity::setY(int y) {
	_y = y;
}

// group
unsigned int PhysicalEntity::getGroup() {
	return _group;
}

void PhysicalEntity::setGroup(unsigned int group) {
	_group = group;
}

// groupMask
unsigned int PhysicalEntity::getGroupMask() {
	return _groupMask;
}

void PhysicalEntity::setGroupMask(unsigned int groupMask) {
	_groupMask = groupMask;
}

bool PhysicalEntity::getCollidesWithGroup(unsigned int group) {
	return (_groupMask & group) > 0;
}