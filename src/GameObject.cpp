#include "GameObject.h"

// Engine
#include "Game.h"

GameObject::GameObject()
  : id_(0),
    owner_(NULL)
{
}
GameObject::GameObject(Game* owner)
  : id_(0),
    owner_(owner)
{
}

GameObject::~GameObject()
{
}
