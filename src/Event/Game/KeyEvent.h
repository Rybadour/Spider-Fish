// ##### Key Event #####
// Fired during the input phase.
// Wraps SDL's keyboard event.

#include "../Core/types.h"

#include "GameEvent.h"

class KeyEvent: public GameEvent {
private:
  SDL_KeyboardEvent &_sdlKeyEvent;
public:
  class static const int type_id;
  
  KeyEvent(const SDL_KeyboardEvent &sdlKeyEvent):
    _sdlKeyEvent(sdlKeyEvent) {
  }
  
  bool isDown() const {
    return _sdlKeyEvent.type == SDL_KEYDOWN;
  }
  
  bool isUp() const {
    return _sdlKeyEvent.type == SDL_KEYUP;
  }
  
  Key::Any getKey() const {
    return _sdlKeyEvent.keysym.sym;
  }
  
  ModKey::Any getMod() const {
    return _sdlKeyEvent.keysym.mod;
  }
             
};               
// this is required so that the event service can identify this event
const int KeyEvent::type_id = types_unique_id++;