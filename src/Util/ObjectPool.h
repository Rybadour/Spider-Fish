#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H

// C++
#include <list>
#include <stack>

using namespace std;

template<class T>
class ObjectPool {

public:

// empty public constructor
ObjectPool();

// take an object from the pool.
T *getObject();

// put an object back into the pool. must have came from this pool.
// do not use an object after it has been released.
// returns true/false for success/failure
void releaseObject(T *object);

// free all objects in pool
void empty();

// return the number of objects in pool
unsigned int getSize();

protected:

private:

// stack of objects in the pool
stack<T *> _pool;

};

#endif