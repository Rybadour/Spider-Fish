#ifndef COLLISION_MANAGER_H
#def COLLISION_MANAGER_H

// C++
#include <tuple>

// Engine
#include <RigidBody.h>

using namespace std;

class CollisionManager {

public:

// adds a PhysicalEntity to be checked for collision
void registerEntity(PhysicalEntity *entity);


void checkCollisions();

protected:

private:

vector<PhysicalEntity *> _entities;

bool _checkIfColliding(PhysicalEntity *entityA, PhysicalEntity *entityB);

};

#endif