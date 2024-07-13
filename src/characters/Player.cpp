#include "Player.h"

void Player::init() {
  this->position = {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2};
  this->movement = 0;
}

void Player::update(){
  this->movement = 0;

  const Uint8* keystates = SDL_GetKeyboardState(NULL);
  if (keystates[SDL_SCANCODE_A]){
    movement += 1;
  }
  if (keystates[SDL_SCANCODE_D]){
    movement -= 1;
  }

  this->position.x += movement * speed;
}

void Player::draw(){

}
