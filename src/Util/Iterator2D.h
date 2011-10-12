#ifndef ITERATOR_ITERATOR_H
#define ITERATOR_ITERATOR_H

#include <boost/iterator/iterator_facade.hpp>

// forward
template<typename It>
class Iterator2D;

/* Iterator2DTraits
 * Contains useful typedefs for Iterator2D
 */
template<typename It>
class Iterator2DTraits {
private:
	static const It _it; // dummy to get type data
	friend class Iterator2D<It>;
	
	typedef Iterator2D<It> Self_t;

	// sub-iterator type
	typedef decltype((*_it).begin()) SubIt_t;

	// sub-iterator dereference type
	typedef decltype(*((*_it).begin())) Value_t;

};

/* Iterator2D
 * Given an iterator, iterates on the values returned by the iterators
 * of the containers returned by the given iterator. Assumed that the
 * containers have begin() and end() methods that return the sub-iterator
 * pairs.
 */
template<typename It>
class Iterator2D
  : public boost::iterator_facade<
    typename Iterator2DTraits<It>::Self_t
  , typename Iterator2DTraits<It>::Value_t
  , boost::forward_traversal_tag
  >
{
public:

  // empty constructor
  Iterator2D()
  {
  }

  // basic constructor
  Iterator2D(It &itStart, It &itEnd)  :
	_it(itStart), _itEnd(itEnd)
	{
		// setup the first sub-iterator, if possible.
		if (_it != _itEnd) {
			(*_it).begin() == (*_it).end();
			_subIt = (*_it).begin();
			_subItEnd = (*_it).end();
			// this sub-iterator may be empty. calling
			// this advances us to the next non-empty one,
			// or will do nothing if the current sub-iterator
			// in fact is not empty.
			nextSubIt();
		}
	}

protected:

private:

	It _it;
	It _itEnd;

	typename Iterator2DTraits<It>::SubIt_t _subIt;
	typename Iterator2DTraits<It>::SubIt_t _subItEnd;

	// setup the next sub-iterator. this method does
	// nothing if the sub-iterator is not at its end.
	// if there are no more sub-iterators available,
	// the iterator will be left at its end.
	void nextSubIt() {
		// grab the first non-empty sub-iterator.
		// stop if the iterator hits its end.
		while (_it != _itEnd && _subIt == _subItEnd) {
			++_it;
			if (_it != _itEnd) {
				_subIt = (*_it).begin();
				_subItEnd = (*_it).end();
			}
		}
	}

	/* required boost iterator methods.
	 */

	friend class boost::iterator_core_access;

	// advances to the next position
	void increment() {
		++_subIt;
		// if we're at the end of this sub-iterator,
		// move on to the start of the next one.
		if (_subIt == _subItEnd) {
			nextSubIt();
		}
	}

	// returns the current value
	typename Iterator2DTraits<It>::Value_t &dereference() const {
		return *_subIt;
	}

	// returns true if iterators are in the same position.
	bool equal(Iterator2D<It> const &other) const {
		// case if either iterator is at the end, then
		// either sub-iterator may be invalid, so don't
		// try and evaluate them.
		if (_it == _itEnd || other._itEnd == other._itEnd) {
			return _it == other._it;
		}
		// the normal case. if both iterators are in the same
		// position, ties are broken on the sub-iterators.
		else {
			return _it == other._itEnd && _subIt == other._subIt;
		}
	}

};

// constructor function
template<typename Iterator>
Iterator2D<Iterator> make_iterator2D(Iterator &it) {
	return Iterator2D<Iterator>(it);
};

#endif