#include <raylib.h>

class Player {
private:
  // Movement
  float speed = 2.0;
  Vector2 position;
  float movement;

  // Animation
  Texture2D idleTexture;
  Rectangle idleFrameRec;
  int currentFrame;

public:
  // Game loop
  void init(const int screenHeight, const int screenWidth);
  void update();
  void draw();

  Player(){
    this->idleTexture = LoadTexture("../assets/characters/knight/_Idle.png");
    this->idleFrameRec = { 0.0f, 0.0f, (float)idleTexture.width / 10, (float)idleTexture.height };

    this->currentFrame = 0;
  }

  ~Player(){
    UnloadTexture(this->idleTexture);
  }
};
