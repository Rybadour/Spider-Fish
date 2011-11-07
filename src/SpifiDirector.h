// ##### SpifiDirector #####
// Controls the flow of Spider-Fish's game from scene to scene. For
// example, this director is responsible for changing from GameScene
// to PauseScene when the game pauses.

#include "Core/Director.h"

class SpifiDirector: public IDirector {

private:

  MenuScene _menuScene;
  GameScene _gameScene;
  PauseScene _pauseScene;
  
  enum ActiveScene {
    MenuScene, GameScene, PauseScene, None
  };
  
  ActiveScene _activeScene;

public:

  // main loop

  virtual void run() {
    // initial scene is the menu
    _activeScene = ActiveScene.MenuScene;
    run = true;
    while (run) {
      switch(activeScene) {
      
      case ActiveScene.MenuScene:
        play(_menuScene);
      break;
      
      case ActiveScene.GameScene:
        play(_gameScene);
      break;
      
      case ActiveScene.PauseScene:
        play(_pauseScene);
      break;
      
      default:
        run = false;
      break;
    };
  };

private:

  // plays one frame of the scene.
  // changes scene appropriately depending on scene exit status.

  void play(MenuScene &scene) {
    switch (_menuScene.update()) {
      
      case MenuScene::ExitStatus.Abort:
      case MenuScene::ExitStatus.Stop:
        _activeScene = ActiveScene.None;
        _menuScene.stop();
      break;
      
      case MenuScene::ExitStatus.Start:
        _activeScene = ActiveScene.GameScene;
        _gameScene.start();
      break;
    };
  }
  
  void play(GameScene &scene) {
    switch (_gameScene.update()) {
      
      case GameScene::ExitStatus.Abort:
        _gameScene.stop();
        _activeScene = ActiveScene.None;
      break;
      
      case GameScene::ExitStatus.Stop:
        _gameScene.stop();
        _activeScene = ActiveScene.MenuScene;
        _menuScene.start();
      break;
      
      case GameScene::ExitStatus.Pause:
        _gameScene.pause();
        _activeScene = ActiveScene.PauseScene;
        _pauseScene.start();
      break;
    }
  }
  
  void play(PauseScene &scene) {
    switch (_pauseScene.update()) {
      
      case PauseScene::ExitStatus.Abort:
        _activeScene = ActiveScene.None;
        _pauseScene.stop();
      break;
      
      case PauseScene::ExitStatus.Stop:
        _pauseScene.stop();
        _activeScene = ActiveScene.GameScene;
        _gameScene.resume();
      break;
    };
  }

};