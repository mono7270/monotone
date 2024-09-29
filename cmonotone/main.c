#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

int GetRandom(int min, int max);
void PlayMusic(Mix_Music* music, SDL_Event* e, bool* playing);

int main(int argc, char* argv[]) {
    bool is_duplicate, playing;
    char input[2];
    int c, i, j, quantity, selected_mode, shuffle;
    int* played_files;
    Mix_Music* music;
    SDL_Event e;

    if (argc < 2) {
        printf("%sの使い方 : 音楽ファイルを引数に指定して下さい。\n", argv[0]);

        return 1;
    }

    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL初期化失敗。SDL_Error : %s\n", SDL_GetError());

        return 1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer初期化失敗。SDL_mixer_Error : %s\n", SDL_GetError());

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
                    printf("1か2を入力して下さい。\n");
                } else {
                    printf(selected_mode == 1 ? "通常再生モード\n"
                                              : "シャッフル再生モード\n");
                    printf("Ctrl+Cでスキップ可能。");
                    break;
                }
            }

            break;
    }

    switch (selected_mode) {
        case 1:
            for (i = 1; i <= quantity; i++) {
                music = Mix_LoadMUS(argv[i]);

                if (music) {
                    playing = true;
                    printf("%2d曲目\n", i);

                    PlayMusic(music, &e, &playing);
                } else {
                    printf("読み込み失敗。\nSDL_mixer_Error : %s\n",
                           Mix_GetError());
                }
            }

            break;

        case 2:
            played_files = (int*)malloc(sizeof(int) * quantity);

            for (i = 1; i <= quantity; i++) {
                while (1) {
                    is_duplicate = false;
                    shuffle = GetRandom(1, quantity);

                    for (j = 0; j < i; j++) {
                        if (played_files[j] == shuffle) {
                            is_duplicate = true;
                            break;
                        }
                    }

                    if (!is_duplicate) {
                        break;
                    }
                }

                music = Mix_LoadMUS(argv[shuffle]);

                if (music) {
                    playing = true;
                    printf("%2d曲目、%2d番\n", i, shuffle);

                    PlayMusic(music, &e, &playing);
                } else {
                    printf("読み込み失敗。\nSDL_mixer_Error : %s\n",
                           Mix_GetError());
                }

                played_files[i - 1] = shuffle;
            }

            free(played_files);

            break;

        default:
            break;
    }

    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}

int GetRandom(int min, int max) { return (rand() % (max - min + 1)) + min; }

void PlayMusic(Mix_Music* music, SDL_Event* e, bool* playing) {
    Mix_PlayMusic(music, 1);

    while (*playing) {
        while (SDL_PollEvent(e) != 0) {
            if (e->type == SDL_QUIT) {
                *playing = false;
            }
        }

        SDL_Delay(100);
    }
}