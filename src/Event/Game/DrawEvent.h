// ##### Draw Event #####
// Fired during the draw phase.

#include "../Core/types.h"

#include "GameEvent.h"

class DrawEvent: public GameEvent {
public:
  class static const int type_id;
  
  DrawEvent() {
  }
  
};
// this is required so that the event service can identify this event
const int DrawEvent::type_id = types_unique_id++;