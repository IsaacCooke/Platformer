#include "src/utils/Include.h"
#include "src/characters/Player.h"
#include <SDL_video.h>

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
    return 1;
  }

  // Initialise SDL_image
  if (!((IMG_Init(IMG_INIT_PNG)) & IMG_INIT_PNG)) {
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

  SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
  SDL_ShowCursor(SDL_DISABLE);

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

  // Set V-Sync
  SDL_GL_SetSwapInterval(-1);

  bool quit = false;
  while (!quit) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
      const Uint8* keystates = SDL_GetKeyboardState(NULL);
      if ((e.type == SDL_QUIT) || (keystates[SDL_SCANCODE_ESCAPE])) {
        quit = true;
      }
    }

    player.update();

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF,
                           0xFF); // White background
    SDL_RenderClear(renderer);    // Clear the window

    player.draw();

    SDL_RenderPresent(renderer); // Update the window
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

// #include <windows.h>
// #include <string>
// #include <iostream>
//
// std::string GetCurrentDirectory()
// {
//     // Buffer to hold the current directory path
//     char buffer[MAX_PATH];
//
//     // Get the current directory path
//     DWORD length = GetCurrentDirectoryA(MAX_PATH, buffer);
//
//     // If the function fails, length will be 0
//     if (length == 0)
//     {
//         std::cerr << "Error getting current directory." << std::endl;
//         return "";
//     }
//
//     // Convert the char array to a std::string and return it
//     return std::string(buffer, length);
// }
//
// int main()
// {
//     std::string currentDirectory = GetCurrentDirectory();
//     if (!currentDirectory.empty())
//     {
//         std::cout << "Current Directory: " << currentDirectory << std::endl;
//     }
//     return 0;
// }
