class GameEvent {
public:
  typedef GameSubscriber subscriber_type;
  virtual public inform(const Subscriber &sub) = 0;
};