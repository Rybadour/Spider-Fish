#ifndef FAUX_CONTAINER_H
#define FAUX_CONTAINER_H

/* FauxContainer
 * Provides both begin() and end() iterators but in fact does not
 * own the storage that the iterators are iterating on.
 */
template<typename Iterator>
class FauxContainer {

public:

	typedef Iterator const_iterator;

	FauxContainer(Iterator const &begin, Iterator const &end) :
		_begin(begin), _end(end)
	{
	}

	// return copy of beginning iterator
	Iterator begin() const {
		return _begin;
	}

	// return copy of end iterator
	Iterator end() const {
		return _end;
	}

protected:

private:

	Iterator const _begin;
	Iterator const _end;

};

#endif