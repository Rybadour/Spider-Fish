// ##### GameScene #####
// Responsible for firing all events to GameObjects.

#include "Core/IScene.h"
#include "Core/types.h"

class GameScene: public IScene {
private:
  
  // keep track of the current time.
  // this is given to applicable events.
  time_t _time;
  
  // events that we fire to GameObjects
  KeyEvent      _keyEvent;
  MotionEvent   _motionEvent;
  ButtonEvent   _buttonEvent;
  PositionEvent _positionEvent;
  DrawEvent     _drawEvent;
  UpdateEvent   _updateEvent;
  
  // event service
  EventService<GameEvent> _service;
  
public:

  enum ExitStatus {
    Abort, Continue, Stop, Pause
  };

  GameScene() {
  }
  
  virtual ~GameScene() {
  }
  
  virtual void start() {
    initTime();
  }
  
  virtual void stop() {
  }
  
  virtual void pause() {
  }
  
  virtual void resume() {
  }

  virtual Exit update() {
    
    // this is the explicit sequence of events
    // note: the only safe time to add/remove subscribers is during
    // the updateAll() call
    ExitStatus exitStatus = handleInput();
    updatePositions();
    handleCollisions();
    drawAll();
    updateAll();
    updateTime();
   
    return exitStatus;
  }
  
  void initTime() {
    // initial time
    _time.totalTicks = SDL_GetTicks();
    _time.deltaTicks = 0;
  }
  
  void updateTime() {
    Uint32 newTime = SDL_GetTicks();
    _time.deltaTicks = newTime - _time.totalTicks;
    _time.totalTicks = SDL_GetTicks();
  }
    
  void updatePositions() {
    _positionEvent = PositionEvent(_time);
    _service.publish(_positionEvent);
  }
  
  void handleCollisions() {
    _collisionManager.reactToCollisions();
  }
  
  void drawAll() {
    _service.publish(_drawEvent);
  }
  
  void updateAll() {
    _updateEvent = UpdateEvent(_time);
    _service.publish(_updateEvent);
  }
  
  // ##### Input handling #####
  // publish all keyboard and mouse input events to all subscribers.
  // window events will determine exit status.
  
  ExitStatus handleInput() {
    
    ExitStatus exitStatus = ExitStatus.Continue;
    bool exitAbort = false;
    SDL_Event event;
    
    while (SDL_PollEvent(&event)) {
      switch(event.type) {
      
      // Keyboard
      
      case SDL_KEYDOWN:
      case SDL_KEYUP:
        _keyEvent = KeyEvent(event.key.keysym);
        _service.publish(_keyEvent);
      break;
      
      // Mouse
      
      case SDL_MOUSEMOTION:
        _motionEvent = MotionEvent(event.motion);
        _service.publish(_motionEvent);
      break;
      
      case SDL_MOUSEBUTTONDOWN:
        _buttonEvent = ButtonEvent(event.button);
        _service.publish(_buttonEvent);
      break;
      
      // Window events
      
      case SDL_ACTIVEEVENT:
        if (!event.active.gain) {
          exitStatus = Exit.Pause;
        }
      break;
      
      case SDL_QUIT:
        exitAbort = true;
      break;
      }
    }
    
    // override any other exit status if we are aborting
    if (exitAbort) {
      exitStatus = Exit.Abort;
    }
    
    return exitStatus;
  }

  
};