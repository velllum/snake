#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include "const.h"
#include "field/field.h"
#include "food/food.h"
#include "snake/snake.h"
#include "game/game.h"
#include "other/kbhit.h"


int main()
{
    setlocale(LC_ALL, "");

    system("setterm -cursor off");
    system("stty -icanon -echo"); // включаем неканонический ввод

    snake_size =5; // Текущий размер змейки >0 Включает голову+размер хвоста (если 1- то только голова)
    timeout =1000000; // время на сон равное 1 сек.
    game_on =true; // Признак продолжения игры
    // snake_x[0] =snake_size; // установить индекс головы по центру массива поля

    char ch; // получить направление движения змейки


    /* ДВИЖЕНИЕ */
    for (int i =0; i <COLUMNS; ++i) // заполнить массив поля символами поля
    {
        field[i] =FIELD_SYMBOL; // переопределяем значения массива
    }

    do // задать направление
    {
        system("clear"); // очистить поле

        std::wcout << L"Задайте направление движения 'Змейки': ";
        std::wcout << "(A, a) - " << WC_LEFT << "; ";
        std::wcout << "(D, d) - " << WC_RIGHT << std::endl;

        ch = getchar();

        switch(ch) // управление через зарезервированные клавиши
        {
            case RIGHT_L: case RIGHT_U: // движение в право
                direction =RIGHT_; // задаем направление движения змейки
                snake_x[0] =snake_size; // установить индекс головы, с учетом размера змейки

                for (int i =1; i <snake_size; ++i) // заполнить массив змейки хвостом
                {
                    snake_x[i] =snake_x[0] -i; // переопределяем значения массива
                }

                break;
            case LEFT_L: case LEFT_U: // движение влево
                direction =LEFT_; // задаем направление движения змейки

                snake_x[0] =COLUMNS -snake_size; // установить индекс головы, с учетом размера змейки

                for (int i =1; i <snake_size; ++i) // заполнить массив змейки хвостом
                {
                    snake_x[i] =snake_x[0] +i; // переопределяем значения массива
                }

                break;
            case 27: case 'q': // выход из программы
                exit(0);
        }
    }
    while(ch !=RIGHT_U && ch !=RIGHT_L && ch !=LEFT_U && ch !=LEFT_L); // выход, если значение направления было установлено


    /* УПРАВЛЕНИЕ */
    do // создаем передвижение змейки
    {

        for (int i =0; i <snake_size; ++i) // создаем передвижение змейки
        {
            switch(direction)
            {
                case RIGHT_: // движение в право

                    // TODO: Проверить за максимальные рамки

                    if (snake_x[i] ==COLUMNS)
                    {
                        field[snake_x[snake_size -1] -1] =FIELD_SYMBOL; // переопределяем оствшееся значение в поле за хвостом
                        snake_x[i] =0; // обнуляем первое значение в массиве координат с индексами
                        continue;
                    }

                    else if (i ==0)
                    {
                        field[snake_x[i]++] =HEAD_SYMBOL; // передаем символ головы в массив
                        continue;
                    }
                    
                    field[snake_x[i]++] =TAIL_SYMBOL; // передаем символ хвоста в массив
                    field[(snake_x[i] -snake_size) +1] =FIELD_SYMBOL; // переопределяем за хвостом значениями поля
                    
                    break;

                case LEFT_: // движение в лево

                    // TODO: ошибка выхода значения массива snake_x за ноль -1

                    if (snake_x[i] ==0)
                    {
                        field[snake_x[snake_size -i]] =FIELD_SYMBOL; // переопределяем оствшееся значение в поле за хвостом
                        snake_x[i] =COLUMNS; // обнуляем первое значение в массиве координат с индексами
                        continue;
                    }

                    else if (i ==0)
                    {
                        field[--snake_x[i]] =HEAD_SYMBOL; // передаем символ головы в массив
                        continue;
                    }


                    field[--snake_x[i]] =TAIL_SYMBOL; // передаем символ хвоста в массив
                    field[(snake_x[i] +snake_size) -1] =FIELD_SYMBOL; // переопределяем за хвостом значениями поля

                    break;
            }
        }

        system("clear"); // очистить поле

        for (int j =0; j <COLUMNS; ++j) // печать результата
        {
            std::wcout << field[j];
        }
        std::cout << std::endl;

        usleep(timeout); // засыпаем на 1 сек =1000000

         if (kbhit() && ((ch =getchar()) =='q' || (ch =getchar()) ==27))
        {
            game_on =false;
        }
    }
    while (game_on);

//    system ("stty cooked");
//    exit(0); //or terminate

    return 0;
}

