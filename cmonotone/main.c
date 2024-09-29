#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("%sの使い方 : 音楽ファイルを引数に指定して下さい。\n", argv[0]);

        return 1;
    }

    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDLを初期化できませんでした。\nSDL_Error : %s\n",
               SDL_GetError());

        return 1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixerを初期化できませんでした。\nSDL_mixer_Error : %s\n",
               SDL_GetError());

        return 1;
    }

    Mix_Music* music = Mix_LoadMUS(argv[1]);

    if (music == NULL) {
        printf("ファイルを読み込めませんでした。\nSDL_mixer_Error : %s\n",
               Mix_GetError());

        return 1;
    }

    Mix_PlayMusic(music, 1);

    while (Mix_PlayingMusic) {
        SDL_Delay(100);
    }

    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}