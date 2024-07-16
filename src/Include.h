#include <iostream>

#ifdef _WIN32
  #include <SDL.h>
  #include <SDL_image.h>
#elif unix
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_image.h>
#endif

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

using namespace std;
