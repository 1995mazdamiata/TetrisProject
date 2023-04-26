#include <stdio.h>
#include "StartScreen.h"


void start::openScreen(){
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        cout << "Error SDL2 Initialization : " << SDL_GetError();
    }
        
    if (IMG_Init(IMG_INIT_PNG) == 0) {
        cout << "Error SDL2_image Initialization";
    }

    SDL_Window* window = SDL_CreateWindow("tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
    if (window == NULL) {
        cout << "Error window creation";
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        cout << "Error renderer creation";
    }

    SDL_Surface* tetris_sur = IMG_Load("tetris.png");
    if (tetris_sur == NULL) {
        cout << "Error loading image: " << IMG_GetError();
    }

    SDL_Texture* tetris_tex = SDL_CreateTextureFromSurface(renderer, tetris_sur);
    if (tetris_tex == NULL) {
        cout << "Error creating texture";
    }

    SDL_FreeSurface(tetris_sur);

    while (true) {
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, tetris_tex, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(tetris_tex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
