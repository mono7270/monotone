#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int i, quantity;
    bool playing;
    Mix_Music* music;
    SDL_Event e;

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

    quantity = argc - 1;

    printf("通常再生モード\n");
    printf("Ctrl+Cでスキップできます。\n");

    for (i = 1; i <= quantity; i++) {
        music = Mix_LoadMUS(argv[i]);

        if (music) {
            playing = true;
            Mix_PlayMusic(music, 1);
            printf("%2d曲目\n", i);

            while (playing) {
                while (SDL_PollEvent(&e) != 0) {
                    if (e.type == SDL_QUIT) {
                        playing = false;
                    }
                }

                while (!Mix_PlayingMusic()) {
                    break;
                }

                SDL_Delay(100);
            }
        } else {
            printf("ファイルを読み込めませんでした。\nSDL_mixer_Error : %s\n",
                   Mix_GetError());
        }
    }

    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}