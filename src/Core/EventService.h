// ##### Event Service #####
// Facilitates an event notifier pattern.

template<typename RootEvent>
class EventService {

private:

  typedef RootEvent::subscriber_type Subscriber;
  typedef decltype(RootEvent::type_id) type_id_t;
  typedef std::set<Subscriber&> subscriber_set_t;
  typedef std::map<type_id_t, subscriber_set_t*> event_map_t;
  
  event_map_t _subscribers;

  // getSubscriberSet
  // returns the subscriber set for a given event type.
  // if the set does not yet exist, it will be made.
  subscriber_set_t *getSubscriberSet(type_id_t typeName) {
    auto subscriberSet = _subscribers.find(typeName);
    // create the set if it doesn't exist.
    if (subscriberSet == _subscribers.end()) {
      subscriber_set_t *newSubSet = new subscriber_set_t;
      _subscribers.insert(event_map_t::value_type(typeName, newSubSet));
      // now this is guaranteed to work
      subscriberSet = _subscribers.find(typeName);
    }
    return subscriberSet;
  }
  
public:
  
  // subscribe
  // Adds a subscriber to an event list.
  
  template<typename T>
  void subscribe(T &event, Subscriber &sub) {
    BOOST_STATIC_ASSERT(boost::is_base_of<Event, RootEvent>::value);
    getSubscriberSet(T::type_id)->insert(sub);
  }
  
  // unsubscribe
  // Removes a subscriber from an event list.
  
  template<typename T>
  void unsubscribe(T &event, Subscriber &sub) {
    BOOST_STATIC_ASSERT(boost::is_base_of<Event, RootEvent>::value); 
    getSubscriberSet(T::type_name)->erase(sub);
  }

  // publish
  // Sends an event to all interested subscribers.
  
  template<typename T>
  void publish(T &event) {
    BOOST_STATIC_ASSERT(boost::is_base_of<Event, RootEvent>::value);
    BOOST_FOREACH(auto sub, getSubscriberSet(T::type_name)) {
      event.inform(sub);
    }
  }
  
};