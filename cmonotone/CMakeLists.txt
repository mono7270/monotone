cmake_minimum_required(VERSION 3.28.3)
project(cmonotone)

set(CMAKE_C_STANDARD 17)

find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)

add_executable(cmonotone main.c)
target_link_libraries(cmonotone SDL2::SDL2 SDL2_mixer::SDL2_mixer)
