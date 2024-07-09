#include <raylib.h>

class Player {
private:
  float speed = 2.0;
  Vector2 position;
  float movement;

public:
  // Game loop
  void init(const int screenHeight, const int screenWidth);
  void update();
  void draw();
};
