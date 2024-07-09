#include "player.h"
#include <raylib.h>

void Player::init(const int screenWidth, const int screenHeight){
  this->position = {(float)screenWidth / 2, (float)screenHeight / 2};
  this->movement = 0;
}

void Player::update(){
  this->movement = 0;
  if (IsKeyDown(KEY_D)) this->movement = 1;
  if (IsKeyDown(KEY_A)) this->movement = -1;

  this->position.x += movement * speed;
}

void Player::draw(){
  DrawCircleV(position, 50, GREEN);
}
