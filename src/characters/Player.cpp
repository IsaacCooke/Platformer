#include "Player.h"

Player::Player(SDL_Renderer *renderer, bool& failed) {
  this->renderLocation = {position.x, position.y, this->renderLocation.w, this->renderLocation.h};

  this->renderer = renderer;

  SDL_Surface *idleBMP = IMG_Load(IDLE_KNIGHT);
  if (idleBMP == nullptr){
    failed = true;
    cerr << IMG_GetError() << endl;
    return;
  }

  SDL_Texture *idleTexture = SDL_CreateTextureFromSurface(this->renderer, idleBMP);
  SDL_FreeSurface(idleBMP);
  if (idleTexture == nullptr){
    failed = true;
    cerr << IMG_GetError() << endl;
  }
  this->idleTexture = idleTexture;

}

Player::~Player(){
  SDL_DestroyTexture(idleTexture);
}

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
  this->renderLocation.x = position.x;
  SDL_RenderCopy(renderer, idleTexture, &renderTarget, &renderLocation);
}
