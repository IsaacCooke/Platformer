#include <iostream>
#include <string>

#ifdef _WIN32
  #include <SDL.h>
  #include <SDL_image.h>
#elif unix
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_image.h>
#endif

#ifdef _WIN32
  #define BASE "../../assets/"
#elif unix
  #define BASE "../assets/"
#endif

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 1200

using namespace std;
