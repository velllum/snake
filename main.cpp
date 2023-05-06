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
    std::setlocale(LC_ALL, "");
    std::system("setterm -cursor off");
    std::system("stty -icanon -echo"); // включаем неканонический ввод

    snake_size =6; // Текущий размер змейки >0 Включает голову+размер хвоста (если 1- то только голова)
    timeout =1000000; // время на сон равное 1 сек.
    game_on =true; // Признак продолжения игры

    char ch; // получить направление движения змейки
    int snake_tail; // последнее значение в хвосте
    int snake_head; // перевое значение, голова


    /* ДВИЖЕНИЕ */
    for (int i =0; i <COLUMNS; ++i) // заполнить массив поля символами поля
    {
        field[i] =FIELD_SYMBOL; // переопределяем значения массива
    }

    do // задать направление
    {
        std::system("clear"); // очистить поле

        // печатаем пользовательскую информацию выбора, направления движения
        std::wcout << L"Задайте направление движения 'Змейки':\n\n";
        std::wcout << "(A, a) - " << WC_LEFT << std::endl;
        std::wcout << "(D, d) - " << WC_RIGHT << std::endl;

        ch =getchar();

        switch(ch) // управление через зарезервированные клавиши
        {
            case RIGHT_L: case RIGHT_U: // движение в право

                direction =RIGHT_; // задаем направление движения змейки
                snake_x[0] =snake_size; // установить индекс головы, с учетом размера змейки

                for (int i =1; i <snake_size; ++i) // заполнить массив змейки хвостом
                {
                    snake_x[i] =snake_x[0] -i;
                }

                break;

            case LEFT_L: case LEFT_U: // движение влево

                direction =LEFT_; // задаем направление движения змейки
                snake_x[0] =LEN_SNAKE_MAX -snake_size; // установить индекс головы, с учетом размера змейки

                for (int i =1; i <snake_size; ++i) // заполнить массив змейки хвостом
                {
                    snake_x[i] =snake_x[0] +i;
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
        switch(direction)
        {
            case RIGHT_: // движение в право

                snake_tail =(snake_x[snake_size -1]); // получить последнее значение за хвостом
                snake_head =snake_x[0]; // получить перевое значение, голову

                for (int i =0; i <snake_size; ++i) // создаем передвижение змейки
                {
                    field[snake_x[i]] =TAIL_SYMBOL; // определяем тело на поле

                    if (snake_x[i] ==COLUMNS) // проверка на максимальное значения длины поля
                    {
                        snake_x[i] =0; // начинаем движение сночало, слева на право
                    }
                    else
                    {
                        snake_x[i]++; // увеличиваем на единицу, делаем шаг вперед
                    }
                }

                field[snake_head] =HEAD_SYMBOL; // передаем символ головы в массив
                field[snake_tail -1] =FIELD_SYMBOL; // меняем послед значение за хвастом

                break;
            
            case LEFT_: // движение в лево

                snake_tail =(snake_x[snake_size -1]); // получить последнее значение за хвостом
                snake_head =snake_x[0]; // получить перевое значение, голову

                for (int i =0; i <snake_size; ++i) // создаем передвижение змейки
                {
                    field[snake_x[i]] =TAIL_SYMBOL; // определяем тело на поле

                    if (snake_x[i] ==0) // проверка на ноль
                    {
                        snake_x[i] =LEN_SNAKE_MAX; // передаем максимальный размер массива змейки
                    }
                    else
                    {
                        snake_x[i]--; // уменьшаем на едницу
                    }
                }

                field[snake_head] =HEAD_SYMBOL; // передаем символ головы в массив
                field[snake_tail !=LEN_SNAKE_MAX? snake_tail +1: 0] =FIELD_SYMBOL; // меняем послед значение за хвастом

                break;
        }

        std::system("clear"); // очистить поле

        std::cout << std::endl;

        for (int j =0; j <COLUMNS; ++j) // печать результата
        {
            std::wcout << field[j] << " ";
        }

        std::wcout << "\t" << L"Направление: " << static_cast<wchar_t>(direction) << std::endl;
        std::wcout << "\t\t\t" << L"Размер: " << snake_size << std::endl;

        std::cout << std::endl;

        usleep(timeout); // засыпаем на 1 сек =1000000

        if (kbhit() && ((ch =getchar()) =='q' || (ch =getchar()) ==27))
        {
            game_on =false;
        }
    }
    while (game_on);

    return 0;
}

