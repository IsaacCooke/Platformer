#include "src/Include.h"
#include "src/characters/Player.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <iostream>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
    return 1;
  }

  // Initialise SDL_image
  if (!(IMG_Init(IMG_INIT_PNG)) & IMG_INIT_PNG) {
    cerr << "IMG_Init Error: " << IMG_GetError() << endl;
    SDL_Quit();
    return 1;
  }

  // Create Window
  SDL_Window *window = SDL_CreateWindow(
      "Platformer Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
      SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (!window) {
    std::cout << "Window could not be created! Error: " << SDL_GetError()
              << std::endl;
    IMG_Quit();
    SDL_Quit();
    return 1;
  }

  // Create Renderer
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    std::cout << "Renderer could not be created. Error: " << SDL_GetError()
              << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  bool failed = false;
  Player player(renderer, failed);
  if (failed){
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cerr << "Image Error: " << IMG_GetError() << endl;
    return -1;
  }
  player.init();

  // Load image
  SDL_Surface *bmp = IMG_Load("../assets/characters/knight/_Idle.png");
  if (bmp == nullptr) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    cerr << "IMG_Load error: " << IMG_GetError() << endl;
    IMG_Quit();
    SDL_Quit();
    return 1;
  }

  // Create texture from surface
  SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, bmp);
  SDL_FreeSurface(bmp);
  if (tex == nullptr) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError()
              << endl;
    IMG_Quit();
    SDL_Quit();
    return 1;
  }

  SDL_Rect renderRect = {0, 0, 128, 128};

  SDL_Rect squareRect;
  squareRect.w = 256; // Set a size for the rectangle
  squareRect.h = 128; // Set a size for the rectangle
  squareRect.x = SCREEN_WIDTH / 2 - squareRect.w / 2;
  squareRect.y = SCREEN_HEIGHT / 2 - squareRect.h / 2;

  bool quit = false;
  while (!quit) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        quit = true;
      }
    }

    player.update();

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF,
                           0xFF); // White background
    SDL_RenderClear(renderer);    // Clear the window

    // SDL_RenderCopy(renderer, tex, &renderRect, &squareRect);
    player.draw();

    SDL_RenderPresent(renderer); // Update the window
  }

  SDL_DestroyTexture(tex);

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
