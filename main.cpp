#include <raylib.h>
#include "src/characters/player.h"

int main() {
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Platformer Game");
  SetTargetFPS(60);

  Player player;
  player.init(screenWidth, screenHeight);

  while (!WindowShouldClose()){

    player.update();

    BeginDrawing();

    ClearBackground(RAYWHITE);
    player.draw();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
