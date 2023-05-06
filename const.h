#ifndef SNAKE_CONST_H
#define SNAKE_CONST_H

const int COLUMNS =10; // Длина игрового поля по горизонтали (включает граничные элементы)
const int LEN_SNAKE_MAX =COLUMNS -1; // Максимальный размер массива змейки (Не должна быть > длины игрового поля-2)

const wchar_t TAIL_SYMBOL =L'\u25A1'; // Символ для хвоста змейки
const wchar_t HEAD_SYMBOL =L'\u25A0'; // Символ для головы змейки
const wchar_t FIELD_SYMBOL =L'\u2022'; // Символ поля клетки
const wchar_t BORDER_SYMBOL ='*'; // Символ бордюра поля

const wchar_t WC_LEFT =L'\u25C0'; // Символ направления в лево
const wchar_t WC_RIGHT =L'\u25B6'; // Символ направления в право
const wchar_t WC_UP =L'\u25B2'; // Символ направления в верх
const wchar_t WC_DOWN =L'\u25BC'; // Символ направления в низ

// Константы для обработки клавиатурного ввода (перечисление из “Задание (игра Змейка)_1 (клавиатурный ввод)” )
enum KEYS {UP_U ='W', UP_L ='w', DOWN_U ='S', DOWN_L ='s', RIGHT_U ='D', RIGHT_L ='d', LEFT_U ='A', LEFT_L ='a'};
enum DIRECTION {UP_=WC_UP, DOWN_=WC_DOWN, RIGHT_=WC_RIGHT, LEFT_=WC_LEFT}; // Перечисление «направление движения

#endif //SNAKE_CONST_H
