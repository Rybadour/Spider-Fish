// ##### Scene Interface ######
//

class IScene {
public:
  virtual ~Scene(){};
  virtual void start() = 0;
  virtual void stop() = 0;
  virtual void pause() = 0;
  virtual void resume() = 0;
  virtual void update() = 0;
};