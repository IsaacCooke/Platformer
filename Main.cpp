#include "src/characters/Player.h"
#include "src/Include.h"
#include <iostream>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
        return 1;
    }

    Player player;
    player.init(); // Initialize player

    SDL_Window *window = SDL_CreateWindow("Platformer Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cout << "Window could not be created! Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer) {
        std::cout << "Renderer could not be created. Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Rect squareRect;
    squareRect.w = 50; // Set a size for the rectangle
    squareRect.h = 50; // Set a size for the rectangle
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

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // White background
        SDL_RenderClear(renderer); // Clear the window
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF); // Black color for the square
        SDL_RenderFillRect(renderer, &squareRect); // Render the square
        SDL_RenderPresent(renderer); // Update the window
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
