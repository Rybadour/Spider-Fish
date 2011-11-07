// ##### Button Event #####
// Fired during the input phase.
// Wraps SDL's mouse motion event.

#include "../Core/types.h"

#include "GameEvent.h"

class ButtonEvent: public GameEvent {
private:
  const SDL_MouseButtonEvent &_sdlButtonEvent;
public:
  class static const int type_id;
  
  MotionEvent(const SDL_MouseButtonEvent &sdlButtonEvent):
    _sdlButtonEvent(sdlButtonEvent) {
  }
  
  bool isDown() const {
    return _sdlButtonEvent.type == SDL_MOUSEBUTTONDOWN;
  }
  
  bool isUp() const {
    return _sdlButtonEvent.type == SDL_MOUSEBUTTONUP;
  }
  
  Button::Any getButton() const {
    return _sdlButtonEvent.which;
  }
  
  int getX() const {
    return _sdlButtonEvent.x;
  }
  
  int getY() const {
    return _sdlButtonEvent.y;
  }
  
};
// this is required so that the event service can identify this event
const int ButtonEvent::type_id = types_unique_id++;