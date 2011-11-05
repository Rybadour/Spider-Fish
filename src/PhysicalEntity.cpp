#include "PhysicalEntity.h"

#include <vector>
#include <cmath>

#include "SDL.h"

#include "Game.h"


PhysicalEntity::PhysicalEntity( Game* owner, SDL_Surface* image, unsigned int group, unsigned int groupMask, int x, int y ):
  GameObject( owner ),
  _veloX( 0 ),
  _veloY( 0 ),
  _sprite (image),
  _x( x ),
  _y( y ),
  _width (image->w),
  _height (image->h),
  _overflowX( 0 ),
  _overflowY( 0 )
{
  // setup basic attributes
  setGroup( group );
  setGroupMask( groupMask );
}

uint PhysicalEntity::getId() const
{
  return _id;
}

// inherited from GameObject
void PhysicalEntity::draw( SDL_Surface* screen )
{
  _sprite.draw( screen , getLeft(), getTop() );
}

void PhysicalEntity::update( int msTimeStep )
{
  _overflowX += _veloX * ( msTimeStep / 1000.0 );
  _overflowY += _veloY * ( msTimeStep / 1000.0 );

  if( _overflowX >= 1 || _overflowX <= -1 )
  {
    _x += floor( _overflowX );
    _overflowX -= floor( _overflowX );
  }
  if( _overflowY >= 1  || _overflowY <= -1 )
  {
    _y += floor( _overflowY );
    _overflowY -= floor( _overflowY );
  }
}

// returns left-most x
int PhysicalEntity::getLeft() const {
  return _x - _width / 2;
}

// returns right-most x
int PhysicalEntity::getRight() const {
  return _x + _width / 2;
}

// returns top-most y
int PhysicalEntity::getTop() const {
  return _y - _height / 2;
}

// returns bottom-most y
int PhysicalEntity::getBottom() const {
  return _y + _height / 2;
}

// width of entity
unsigned int PhysicalEntity::getWidth() const {
  return _width;
}

void PhysicalEntity::setWidth( unsigned int width ) {
  _width = width;
}

// height of entity
unsigned int PhysicalEntity::getHeight() const {
  return _height;
}

void PhysicalEntity::setHeight( unsigned int height ) {
  _height = height;
}

// center x position
int PhysicalEntity::getX() const {
  return _x;
}

void PhysicalEntity::setX( int x ) {
  _x = x;
}

// center y position
int PhysicalEntity::getY() const {
  return _y;
}

void PhysicalEntity::setY( int y ) {
  _y = y;
}

//get/set velocity
float PhysicalEntity::getVeloY() const {
  return _veloY;
}
void PhysicalEntity::setVeloY( float y ) {
  _veloY = y;
}
float PhysicalEntity::getVeloX() const {
  return _veloX;
}
void PhysicalEntity::setVeloX( float x ) {
  _veloX = x;
}

// group
unsigned int PhysicalEntity::getGroup() const {
  return _group;
}

void PhysicalEntity::setGroup( unsigned int group ) {
  _group = group;
}

// groupMask
unsigned int PhysicalEntity::getGroupMask() const {
  return _groupMask;
}

void PhysicalEntity::setGroupMask( unsigned int groupMask ) {
  _groupMask = groupMask;
}

