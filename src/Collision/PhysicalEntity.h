#ifndef PHYSICAL_ENTITY_H
#def PHYSICAL_ENTITY_H

class PhysicalEntity {

public:

// static factory method
PhysicalEntity &create(unsigned int width, unsigned int height, int x,
  int y);

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
setWidth(unsigned int width);

// height of entity
unsigned int getHeight();
setHeight(unsigned int height);

// top left x position
int getX();
void setX(int x);

// top left y position
int getY();
void setY(int y);

protected:

private:

// keeps track of next id
static unsigned int _nextId = 0;

// allocation for entities
static vector<PhysicalEntity>;

// instance variables
unsigned int id;
unsigned int group;
int _x;
int _y;
unsigned int _width;
unsigned int _height;

};

#endif