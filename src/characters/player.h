#include <raylib.h>

enum PlayerState {
  IDLE,
  RUN,
};

class Player {
private:
  // Movement
  float speed = 2.0;
  Vector2 position;
  float movement;

  // State
  PlayerState state = IDLE;

  // Animation Textures
  Texture2D idleTexture; // 10 frames
  Texture2D runTexture; // 8 frames

  // Animation Rectangles
  Rectangle idleFrameRec;
  Rectangle runFrameRec;

  // Animation Meta
  int currentFrame;
  int framesCounter = 0;
  int framesSpeed = 8;
  Texture activeTexture;
  Rectangle activeFrameRec;

public:
  // Game loop
  void init(const int screenHeight, const int screenWidth);
  void update();
  void draw();

  Player(){
    // Initialise Textures
    this->idleTexture = LoadTexture("../assets/characters/knight/_Idle.png");
    this->runTexture = LoadTexture("../assets/characters/knight/_Run.png");

    // Initialse FrameRecs
    this->idleFrameRec = { 0.0f, 0.0f, (float)idleTexture.width / 10, (float)idleTexture.height };
    this->runFrameRec = { 0.0f, 0.0f, (float)runTexture.width / 8, (float)runFrameRec.height };

    // Initialise Animation Meta
    this->currentFrame = 0;
    this->activeTexture = idleTexture;
    this->activeFrameRec = idleFrameRec;
  }

  ~Player(){
    // Unload Textures
    UnloadTexture(this->idleTexture);
    UnloadTexture(this->runTexture);
  }
};
