#ifndef PHYSICAL_ENTITY_H
#define PHYSICAL_ENTITY_H

#include <vector>

class PhysicalEntity {

public:

// basic constructor
PhysicalEntity(unsigned int width, unsigned int height, unsigned int x, unsigned int y);

// returns entity id
unsigned int getId();
  
// returns left-most x
int getLeft();

// returns right-most x
int getRight();

// returns top-most y
int getTop();

// returns bottom-most y
int getBottom();

// width of entity
unsigned int getWidth();
void setWidth(unsigned int width);

// height of entity
unsigned int getHeight();
void setHeight(unsigned int height);

// top left x position
int getX();
void setX(int x);

// top left y position
int getY();
void setY(int y);

// group
unsigned int getGroup();
void setGroup(unsigned int group);

// groupMask
unsigned int getGroupMask();
void setGroupMask(unsigned int groupMask);

bool getCollidesWithGroup(unsigned int group);

// TODO: should be private
// keeps track of next id
static unsigned int _nextId;

protected:

private:

// instance variables
unsigned int _id;
unsigned int _group;
unsigned int _groupMask;

// top left
int _x;
int _y;

unsigned int _width;
unsigned int _height;

};

#endif