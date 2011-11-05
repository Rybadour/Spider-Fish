// GAME
#include "GameObject.h"
#include "SpiderFish.h"
#include "Game.h"


GameObject::GameObject() :
  _id(0),
  _owner(NULL),
  _alive(true)
{
}

GameObject::GameObject(Game* owner) :
  _id(0),
  _owner(owner),
  _alive(true)
{
}

GameObject::~GameObject()
{
}
