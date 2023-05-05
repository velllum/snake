#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "../const.h"

extern int snake_size; // Текущий размер змейки >0 Включает голову+размер хвоста (если 1- то только голова)
extern int snake_x[LEN_SNAKE_MAX]; // Массив координат змейки по горизонтали (X)
extern DIRECTION direction; // Направление движения змейки

#endif //SNAKE_SNAKE_H
