#include "PhysicalEntity.h"

PhysicalEntity &PhysicalEntity::create(unsigned int width,
  unsigned int height, int x, int y) {
  
  // init new entity
  PhysicalEntity entity(width, height, x, y);
  entity._id = _nextId;
  ++_nextId;
  entity._width = width;
  entity._height = height;
  entity._x = x;
  entity._y = y;
  
  // save it
  _entities.push_back(entity);
  
  // return it
  return _entities.back();
  
};

int PhysicalEntity::getLeft() {
  return _x;
}

int PhysicalEntity::getRight() {
  return _x + _width;
}

int PhysicalEntity::getTop() {
  return _y;
}

int PhysicalEntity::getBottom() {
  return _y + _height;
}

unsigned int PhysicalEntity::getWidth() {
  return _width;
}

void PhysicalEntity::setWidth(unsigned int width) {
  _width = width;
}

unsigned int PhysicalEntity::getHeight() {
  return _height;
}

void PhysicalEntity::setHeight(unsigned int height) {
  _height = height;
}

int PhysicalEntity::getX() {
  return _x;
}

void PhysicalEntity::setX(int x) {
  _x = x;
}

int PhysicalEntity::getY() {
  return _y;
}

void PhysicalEntity::setY(int y) {
  _y = y;
}