#ifndef ITERATOR_ITERATOR_H
#define ITERATOR_ITERATOR_H

#include <boost/iterator/iterator_facade.hpp>

template<typename Derived, typename It, typename SubIt, typename Value>
class IteratorIterator
  : public boost::iterator_facade<
    IteratorIterator<Derived, It, SubIt, Value>
  , Value
  , boost::forward_traversal_tag
  >
{
public:

  //template<typename A>
  IteratorIterator(It &itStart, It &itEnd)
  {
	_it = itStart;
	_itEnd = itEnd;
	if (_it != _itEnd) {
	  _subIt = subItBegin();
	  _subItEnd = subItEnd();
	}
  }

protected:

  // return beginning iterator of the current sub-iterator
  SubIt subItBegin() {
    return static_cast<Derived*>(this)->subItBegin();
  }
  
  // return end iterator of the current sub-iterator
  SubIt subItEnd() {
    return static_cast<Derived*>(this)->subItEnd();
  }

  It &getIt() {
	return _it;
  }

private:

  typedef IteratorIterator<Derived, It, SubIt, Value> thisItIt;

  // iterator
  It _it;
  It _itEnd;
  
  // current sub iterator
  SubIt _subIt;
  SubIt _subItEnd;
  
  friend class boost::iterator_core_access;
  
  void increment()
  {
    if (!incrementSubIt()) {
      incrementIt();
    }
  }
  
  // advances the sub-iterator by one if possible.
  // return true if it was possible.
  bool incrementSubIt() {
	  if (_subIt != _subItEnd) {
		++_subIt;
		return _subIt != _subItEnd;
	  }
	  return false;
	}
  
  // advances the iterator by one if possible.
  // if possible, updates the sub-iterator and returns true.
  // if not possible, returns false.
  bool incrementIt() {
	  if (_it != _itEnd) {
		++_it;
	  }
	  // skip over empty sub iterators
	  while (_it != _itEnd && subItBegin() == subItEnd()) {
		  ++_it;
	  }
	  if (_it != _itEnd) {
		_subIt = subItBegin();
		_subItEnd = subItEnd();
		return true;
	  }
	  return false;
	}
  
  bool equal(thisItIt const& other) const
  {
    if (_it == _itEnd) {
      return _it == other._it;
    }
    return _it == other._it && _subIt == other._subIt;
  }
  
  Value &dereference() const
  {
    return *_subIt;
  }
  
};

#endif