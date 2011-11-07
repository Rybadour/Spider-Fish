// ##### Motion Event #####
// Fired during the input phase.
// Wraps SDL's mouse motion event.

#include "../Core/types.h"

#include "GameEvent.h"

class MotionEvent: public GameEvent {
private:
  const SDL_MouseMotionEvent &_sdlMotionEvent;
public:
  class static const int type_id;
  
  MotionEvent(const SDL_MouseMotionEvent &sdlMotionEvent):
    _sdlMotionEvent(sdlMotionEvent) {
  }
  
  int getX() const {
    return _sdlMotionEvent.x;
  }
  
  int getY() const {
    return _sdlMotionEvent.y;
  }
  
  int getRelX() const {
    return _sdlMotionEvent.relX;
  }
  
  int getRelY() const {
    return _sdlMotionEvent.relY;
  }
  
  int isButtonDown(Button::Any button) const {
    return SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(button);
  }
  
};
// this is required so that the event service can identify this event
const int MotionEvent::type_id = types_unique_id++;