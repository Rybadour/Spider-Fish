// ##### Position Event #####
// Fired during the position update phase.

#include "../Core/types.h"

#include "GameEvent.h"

class PositionEvent: public GameEvent {
private:
  time_t &_time;
public:
  class static const int type_id;
  
  PositionEvent(time_t &time):
    _time(time) {
  }
  
  const time_t &getTime() {
    return _time;
  };
  
};
// this is required so that the event service can identify this event
const int PositionEvent::type_id = types_unique_id++;