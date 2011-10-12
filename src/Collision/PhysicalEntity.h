#ifndef PHYSICAL_ENTITY_H
#define PHYSICAL_ENTITY_H

#include <vector>

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
class PhysicalEntity {

public:

	// empty constructor
	PhysicalEntity() { }

	// minimal constructor for a valid PhysicalEntity object.
	PhysicalEntity(unsigned int group, unsigned int groupMask, unsigned int width,
		unsigned int height, unsigned int x, unsigned int y);

	// returns entity id
	unsigned int getId() const;
  
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
	void setWidth(unsigned int width);

	// height of entity
	unsigned int getHeight() const;
	void setHeight(unsigned int height);

	// top left x position
	int getX() const;
	void setX(int x);

	// top left y position
	int getY() const;
	void setY(int y);

	// group
	unsigned int getGroup() const;
	void setGroup(unsigned int group);

	// groupMask
	unsigned int getGroupMask() const;
	void setGroupMask(unsigned int groupMask);

	// test if this PhysicalEntity will collide with the
	// given group.
	bool getCollidesWithGroup(unsigned int group) const;

protected:

private:

	// keeps track of next id
	static unsigned int _nextId;

	// id of this physical entity
	unsigned int _id;

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

	void setId(unsigned int id);

};

#endif