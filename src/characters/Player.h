#include "../Include.h"
#include "../maths/Vector.h"

class Player {
private:
  // Movement
  float speed;
  Vector2 position;
  float movement;

  // Animation
  SDL_Rect renderTarget = {0, 0, 128, 128};
  SDL_Rect renderLocation = {0, 0, 256, 128};
  SDL_Texture *idleTexture;
  SDL_Renderer *renderer;

public:
  Player(SDL_Renderer *renderer, bool& failed);
  ~Player();
  void init();
  void update();
  void draw();
};
