#ifndef ANY_FORWARD_ITERATOR_H
#define ANY_FORWARD_ITERATOR_H

/*
 * does a new/delete
 */
template<typename Value>
class AnyForwardIterator {
public:

  // TODO: how to avoid stuff like this?
  AnyForwardIterator() { }

  template<typename Iterator>
  AnyForwardIterator(Iterator const &it) {
    _it = new adapter<Iterator>(it);
  }
  
  ~AnyForwardIterator() {
    delete _it;
  }
  
  void operator ++() {
    ++(*_it);
  }
  
  bool operator ==(AnyForwardIterator<Value> const &other) const {
    return (*_it) == other._it;
  }
  
  bool operator !=(AnyForwardIterator<Value> const &other) const {
    return !(*this == other);
  }
  
  Value operator *() const {
    return *(*_it);
  }
  
protected:

private:

  class wrapper {
  public:
    virtual void operator ++() = 0;
    virtual bool operator ==(wrapper *other) const = 0;
    virtual Value operator *() const = 0;
  };
  
  template<typename Iterator>
  class adapter: public wrapper {
  public:
  
    adapter(Iterator const &it) : _it(it) {
    }
    
    void operator ++() {
      ++_it;
    }
    
    bool operator ==(wrapper *other) const {
      return _it == static_cast<adapter<Iterator> *>(other)->_it;
    }
    
    Value operator *() const {
      return *_it;
    }
    
  private:
  
    Iterator _it;
  
  };
  
  wrapper *_it;
  
};

#endif