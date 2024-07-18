#include "../utils/Include.h"
#include "../maths/Vector.h"
#include "../utils/AssetFilePaths.h"

class Player {
private:
  // Movement
  float speed = 0.005;
  Vector2 position {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2};
  float movement;

  // Animation
  SDL_Rect renderTarget = {0, 0, 128, 128};
  SDL_Rect renderLocation = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 256, 128};
  SDL_Texture *idleTexture;
  SDL_Renderer *renderer;

public:
  Player(SDL_Renderer *renderer, bool& failed);
  ~Player();
  void init();
  void update();
  void draw();
};
