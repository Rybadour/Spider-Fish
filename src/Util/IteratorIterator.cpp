#include "IteratorIterator.h"

/*template<typename Derived, typename It, typename SubIt, typename Value>
template<typename A>
IteratorIterator<Derived, It, SubIt, Value>::IteratorIterator(A &itStart, A &itEnd)
{
  _it = itStart;
  _itEnd = itEnd;
  if (_it != _itEnd) {
    _subIt = subItBegin();
    _subItEnd = subItEnd();
  }
}

template<typename Derived, typename It, typename SubIt, typename Value>
void IteratorIterator<Derived, It, SubIt, Value>::increment()
{
  if (!incrementSubIt()) {
    incrementIt();
  }
}

template<typename Derived, typename It, typename SubIt, typename Value>
bool IteratorIterator<Derived, It, SubIt, Value>::incrementSubIt() {
  if (_subIt != _subItEnd) {
    ++_subIt;
    return _subIt != _subItEnd;
  }
  return false;
}

template<typename Derived, typename It, typename SubIt, typename Value>
bool IteratorIterator<Derived, It, SubIt, Value>::incrementIt() {
  if (_it != _itEnd) {
    ++_it;
  }
  // skip over empty sub iterators
  while (_it != _itEnd && _it->begin() == _it->end()) {
      ++_it;
  }
  if (_it != _itEnd) {
    _subIt = subItBegin();
    _subItEnd = subItEnd();
    return true;
  }
  return false;
}


template<typename Derived, typename It, typename SubIt, typename Value>
bool IteratorIterator<Derived, It, SubIt, Value>::equal(thisItIt const& other) const
{
  if (_it == _itEnd) {
    return _it == other._it;
  }
  return _it == other._it && _subIt == other._subIt;
}

template<typename Derived, typename It, typename SubIt, typename Value>
Value &IteratorIterator<Derived, It, SubIt, Value>::dereference() const 
{
  return *_subIt;
}
*/