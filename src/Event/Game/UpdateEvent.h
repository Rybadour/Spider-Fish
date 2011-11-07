// ##### Update Event #####
// Fired during the update phase.

#include "../Core/types.h"

#include "GameEvent.h"

class UpdateEvent: public GameEvent {
private:
  time_t &_time;
public:
  class static const int type_id;
  
  UpdateEvent(time_t &time):
    _time(time) {
  }
  
  const time_t &getTime() {
    return _time;
  };
  
};
// this is required so that the event service can identify this event
const int UpdateEvent::type_id = types_unique_id++;