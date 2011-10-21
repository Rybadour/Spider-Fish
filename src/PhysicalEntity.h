#ifndef PHYSICAL_ENTITY_H
#define PHYSICAL_ENTITY_H

#include <vector>

#include "SDL.h"

#include "GameObject.h"
#include "Sprite.h"

/* PhysicalEntity
 * Represents a rigid body in the physics simulation.
 * - All rigid bodies are currently represented as rectangles.
 * - Each PhysicalEntity is assigned its own id number; this
 *   can be used to uniquely identify a PhysicalEntity.
 * - A PhysicalEntity may belong to one group.
 * - All group numbers must be powers of 2. For 32-bit numbers,
 *   this means there may only be 32 groups.
 * - A PhysicalEntity has a groupMask, which is a bitmask
 *   of which groups the PhysicalEntity collides with.
 */
class PhysicalEntity : public GameObject
{

  public:
    // minimal constructor for a valid PhysicalEntity object.
    PhysicalEntity( Game* owner, SDL_Surface* image, unsigned int group, unsigned int groupMask, int x, int y );

    // inherited from GameObject
    virtual void draw( SDL_Surface*screen );
    virtual void update( int msTimeStep );

    // returns left-most x
    int getLeft() const;

    // returns right-most x
    int getRight() const;

    // returns top-most y
    int getTop() const;

    // returns bottom-most y
    int getBottom() const;

    // width of entity
    unsigned int getWidth() const;
    void setWidth( unsigned int width );

    // height of entity
    unsigned int getHeight() const;
    void setHeight( unsigned int height );

    // center x position
    int getX() const;
    void setX( int x );

    // center y position
    int getY() const;
    void setY( int y );

    float getVeloX() const;
    void setVeloX( float x );

    float getVeloY() const;
    void setVeloY( float Y );

    // group
    unsigned int getGroup() const;
    void setGroup( unsigned int group );

    // groupMask
    unsigned int getGroupMask() const;
    void setGroupMask( unsigned int groupMask );

    uint getId() const;

  protected:
    float _veloX; // pixels/sec
    float _veloY; // pixels/sec
    Sprite _sprite;
  private:

    // group number this entity belongs to. must be power of 2.
    unsigned int _group;

    // bitmask of groups this entity collides with.
    unsigned int _groupMask;

    // top left
    int _x;
    int _y;

    // dimensions
    unsigned int _width;
    unsigned int _height;

    float _overflowX;
    float _overflowY;
};

#endif
