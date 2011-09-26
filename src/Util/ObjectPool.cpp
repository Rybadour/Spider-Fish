// Engine
#include "ObjectPool.h"

template<class T>
ObjectPool<T>::ObjectPool() {
  // empty constructor
};

template<class T>
T *ObjectPool<T>::getObject() {

  // hand out an object in the pool if one available
  if (_pool.size() > 0) {
	T *obj = _pool.top();
	_pool.pop();
    return obj;
  }
  
  // make a new object otherwise
  else {
    return new T;
  }
  
};

template<class T>
void ObjectPool<T>::releaseObject(T *obj) {
  
  // release the object into the pool otherwise
  _pool.push(obj);

};

template<class T>
void ObjectPool<T>::empty() {

  // pop everything out of the pool and free those objects from memory
  T *obj;
  while (_pool.size() > 0) {
    obj = _pool.top();
	_pool.pop();
	delete obj;
  }

};

template<class T>
unsigned int ObjectPool<T>::getSize() {
  return _pool.size();
}



