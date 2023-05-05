#ifndef SNAKE_CONST_H
#define SNAKE_CONST_H

const int COLUMNS =10; // Длина игрового поля по горизонтали (включает граничные элементы)
const int LEN_COL =COLUMNS -1; // длинна массива
const int LEN_SNAKE_MAX =LEN_COL; // Максимальный размер массива змейки (Не должна быть > длины игрового поля-2)

const wchar_t TAIL_SYMBOL =L'\u25A1'; // Символ для хвоста змейки
const wchar_t HEAD_SYMBOL =L'\u25A0'; // Символ для головы змейки
const wchar_t FIELD_SYMBOL =L'\u2022'; // Символ поля клетки
const wchar_t BORDER_SYMBOL ='*'; // Символ бордюра поля

const wchar_t WC_LEFT =L'\u25C0'; // Символ направления в лево
const wchar_t WC_RIGHT =L'\u25B6'; // Символ направления в право
const wchar_t WS_UP =L'\u25B2'; // Символ направления в верх
const wchar_t WS_DOWN =L'\u25BC'; // Символ направления в низ

//enum KEYS {UP_U =87, UP_L =199, DOWN_U =83, DOWN_L =115, RIGHT_U =68, RIGHT_L =100, LEFT_U =65, LEFT_L =97};

// Константы для обработки клавиатурного ввода (перечисление из “Задание (игра Змейка)_1 (клавиатурный ввод)” )
enum KEYS {UP_U ='W', UP_L ='w', DOWN_U ='S', DOWN_L ='s', RIGHT_U ='D', RIGHT_L ='d', LEFT_U ='A', LEFT_L ='a'};
enum DIRECTION {UP_, DOWN_, RIGHT_, LEFT_}; // Перечисление «направление движения

#endif //SNAKE_CONST_H
