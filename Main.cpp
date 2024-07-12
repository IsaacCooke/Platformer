#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>

#ifdef _WIN32
  #include <SDL.h>
#elif unix
  #include <SDL2/SDL.h>
#endif

using namespace std;

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char* argv[]){

  (void)argc;
  (void)argv;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
    return 0;
	}

  #if defined linux && SDL_VERSION_ATLEAST(2, 0, 8)
    // Disable compositor bypass
    if(!SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0"))
    {
        std::cout << "SDL can not disable compositor bypass!" << std::endl;
        return 0;
    }
  #endif

  // Create Window
  SDL_Window *window = SDL_CreateWindow("Platformer Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if (!window){
    cout << "Window could not be created! Error: " << SDL_GetError() << endl;
  } else {
    // Create renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
      cout << "Renderer could not be created. Error: " << SDL_GetError() << endl;
    } else {

      SDL_Rect squareRect;

      // Set dimensions
      squareRect.x = min(SCREEN_WIDTH, SCREEN_HEIGHT) / 2;
      squareRect.y = min(SCREEN_WIDTH, SCREEN_HEIGHT) / 2;

      // Set position
      squareRect.x = SCREEN_WIDTH / 2 - squareRect.w / 2;
      squareRect.y = SCREEN_HEIGHT / 2 - squareRect.h /2;


      bool quit = false;

      // Event loop
      while (!quit){
        SDL_Event e;

        // Wait for the next event
        SDL_WaitEvent(&e);

        // Check if event is to quit
        if (e.type == SDL_QUIT){
          quit = true;
        }

        // Set background
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        // Draw filled square
        SDL_RenderFillRect(renderer, &squareRect);

        // Update screen
        SDL_RenderPresent(renderer);
      }
    }

    // Destroy window
    SDL_DestroyWindow(window);
  }

  // Quit SDL
  SDL_Quit();

	return 0;
}
