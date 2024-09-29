#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int GetRandom(int min, int max);
void PlayMusic(Mix_Music* music, const char* argv, SDL_Event* e, bool* playing);

int main(int argc, char* argv[]) {
    bool is_duplicate, playing;
    char input[4];
    int c, i, j, quantity, selected_mode, shuffle;
    int* played_files;
    Mix_Music* music = NULL;
    SDL_Event e;

    if (argc < 2) {
        printf("%s の使い方 : 音楽ファイルを引数に指定して下さい。\n", argv[0]);

        return 1;
    }

    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL初期化失敗。SDL_Error : %s\n", SDL_GetError());

        return 1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer初期化失敗。SDL_mixer_Error : %s\n", Mix_GetError());

        return 1;
    }

    quantity = argc - 1;

    switch (quantity) {
        case 1:
            selected_mode = 1;
            break;

        default:
            while (1) {
                printf("再生モードを選択(1:通常再生、2:シャッフル再生) : ");
                fgets(input, sizeof(input), stdin);

                if (input[strlen(input) - 1] != '\n') {
                    while ((c = getchar()) != '\n' && c != EOF);
                }

                selected_mode = atoi(input);

                if (selected_mode != 1 && selected_mode != 2) {
                    printf("1 か 2 を入力して下さい。\n");
                } else {
                    printf(selected_mode == 1 ? "通常再生モード\n"
                                              : "シャッフル再生モード\n");
                    printf("Ctrl+C でスキップ可能。\n");
                    break;
                }
            }

            break;
    }

    switch (selected_mode) {
        case 1:
            for (i = 1; i <= quantity; i++) {
                printf("%2d 曲目\n", i);
                PlayMusic(music, argv[i], &e, &playing);
            }

            break;

        case 2:
            played_files = (int*)malloc(sizeof(int) * quantity);

            if (played_files == NULL) {
                printf("メモリの確保に失敗しました。\n");

                return 1;
            }

            for (i = 0; i < quantity; i++) {
                played_files[i] = -1;
            }

            for (i = 1; i <= quantity; i++) {
                while (1) {
                    is_duplicate = false;
                    shuffle = GetRandom(1, quantity);

                    for (j = 0; j < i - 1; j++) {
                        if (played_files[j] == shuffle) {
                            is_duplicate = true;
                            break;
                        }
                    }

                    if (!is_duplicate) {
                        break;
                    }
                }

                printf("%2d 曲目、%2d 番\n", i, shuffle);
                PlayMusic(music, argv[shuffle], &e, &playing);

                played_files[i - 1] = shuffle;
            }

            free(played_files);

            break;

        default:
            break;
    }

    if (music != NULL) {
        Mix_FreeMusic(music);
        music = NULL;
    }

    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}

int GetRandom(int min, int max) { return (rand() % (max - min + 1)) + min; }

void PlayMusic(Mix_Music* music, const char* argv, SDL_Event* e,
               bool* playing) {
    music = Mix_LoadMUS(argv);

    if (music) {
        *playing = true;
        Mix_PlayMusic(music, 1);

        while (*playing) {
            while (SDL_PollEvent(e) != 0) {
                if (e->type == SDL_QUIT) {
                    *playing = false;
                }
            }

            if (!Mix_PlayingMusic()) {
                *playing = false;
            }

            SDL_Delay(100);
        }

        Mix_FreeMusic(music);
    } else {
        printf("読み込み失敗。\nSDL_mixer_Error : %s\n", Mix_GetError());
    }
}