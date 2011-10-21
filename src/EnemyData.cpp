#include "SDL.h"

#include "EnemyData.h"

EnemyData::EnemyData( int type, Uint32 time, int x ):
  _type( type ),
  _time( time ),
  _x( x )
{
}

EnemyData::~EnemyData()
{
}

Uint32 EnemyData::getTime()
{
  return _time;
}

int EnemyData::getType()
{
  return _type;
}

int EnemyData::getX()
{
  return _x;
}
