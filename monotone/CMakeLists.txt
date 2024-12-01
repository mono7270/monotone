cmake_minimum_required(VERSION 3.28.3)
project(monotone)

set(CMAKE_C_STANDARD 17)

find_package(SDL2 REQUIRED)
# find_package(SDL2_mixer REQUIRED)

add_executable(monotone main.c)
target_link_libraries(monotone SDL2::SDL2)
