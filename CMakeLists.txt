cmake_minimum_required(VERSION 3.16)
project(snake_3)

#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 98)

add_executable(${PROJECT_NAME} main.cpp snake/snake.cpp game/game.cpp food/food.cpp field/field.cpp other/kbhit.cpp other/kbhit.h)
