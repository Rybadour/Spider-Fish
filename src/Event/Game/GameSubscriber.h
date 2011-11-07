// ##### Game Subscriber #####
// Anything that wants to receive GameEvents must be a GameSubscriber.
//

class GameSubscriber {
public:
  typedef GameEvent event_type;
  
  // all GameEvents must be listed here. this is the tradeoff
  // for using the visitor pattern.
  virtual void handleEvent(const KeyEvent&){}
  virtual void handleEvent(const MotionEvent&){}
  virtual void handleEvent(const ButtonEvent&){}
  virtual void handleEvent(const PositionEvent&){}
  virtual void handleEvent(const DrawEvent&){}
  virtual void handleEvent(const UpdateEvent&){}
}