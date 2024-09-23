#include "SDL2/SDL_render.h"
#include <SDL2/SDL.h>
#include <stdio.h>

typedef struct {
    int x, y;
    short life;
    char *name;
} Man;

// Putting a const pointer passes a struct by reference; you cannot change the struct but it saves memory
void function( Man *man) { // Add cost * to a struct or other variable thats usually passed by value to make it a pointer
  //man->x = 100; // man.x = 100; if passing by value instead of reference
  man->life = 100;
  printf("life: %d\n", man->life);
}

int main(void) {
    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Init(SDL_INIT_VIDEO); //Initialize sdl2

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create application window
    window = SDL_CreateWindow("Game Window", // window title
                               SDL_WINDOWPOS_UNDEFINED, // initial x position
                               SDL_WINDOWPOS_UNDEFINED, // initial y position
                               640, // width in px
                               480, // height in px
                               0); // flags
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Set drawing color to blue
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    // Clear the screen to blue
    SDL_RenderClear(renderer);
    // Set drawing color to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_Rect rect = { 220, 140, 200, 200 };
    SDL_RenderFillRect(renderer, &rect);
    // Present the renderer
    SDL_RenderPresent(renderer);
    
    SDL_Delay(2000);

    // Event loop
    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

