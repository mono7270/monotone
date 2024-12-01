#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main(int argc, char* argv[]) {
    bool playing = true;
    SDL_Event event;
    SDL_Window* window = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL初期化失敗。SDL_Error: %s\n", SDL_GetError());

        return 1;
    }

    window = SDL_CreateWindow("monotone", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
                              WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("ウィンドウ作成失敗。SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();

        return 1;
    }

    while (playing) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                playing = false;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}