#include "player.h"
#include <raylib.h>
#include <iostream>

void Player::init(const int screenWidth, const int screenHeight){
  this->position = {(float)screenWidth / 2, (float)screenHeight / 2};
  this->movement = 0;
}

void Player::update(){
  // Movement
  this->movement = 0;
  if (IsKeyDown(KEY_D)) this->movement = 1;
  if (IsKeyDown(KEY_A)) this->movement = -1;

  this->position.x += movement * speed;

  // Set State
  if (movement != 0){
    state = RUN;
    activeTexture = runTexture;
    activeFrameRec = runFrameRec;
    std::cout << "In run state" << std::endl;
  } else {
    state = IDLE;
    activeTexture = runTexture;
    activeFrameRec = idleFrameRec;
  }

  // Animation
  framesCounter++;
  if (framesCounter >= (60 / framesSpeed )){
    framesCounter = 0;
    currentFrame++;

    switch (state) {
      case RUN:
        if (currentFrame > 7) currentFrame = 0;
        runFrameRec.x = (float)currentFrame * (float)runTexture.width / 8;
        break;
      default:
        if (currentFrame > 9) currentFrame = 0;
        idleFrameRec.x = (float)currentFrame * (float)idleTexture.width / 10;
        break;
    }

  }
}

void Player::draw(){
  // Render sprite
  DrawTextureRec(activeTexture, activeFrameRec, position, WHITE);
  std::cout << activeFrameRec.width << std::endl;
}
