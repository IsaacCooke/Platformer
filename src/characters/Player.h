#include "../Include.h"
#include "../maths/Vector.h"

class Player {
private:
  float speed;
  Vector2 position;
  float movement;

public:
  void init();
  void update();
  void draw();
};
