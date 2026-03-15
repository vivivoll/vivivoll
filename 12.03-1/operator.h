#pragma once
#include <iostream>
using namespace std;

class Mathematics{
private:
    int *array; //Динамический массив
    int size; //Размер массива
    
public:

    //Конструктор по умолчанию 
    Mathematics();

    //Конструктор с параметрами
    Mathematics(int *arr, int s);

    //Конструктор копирования
    Mathematics(const Mathematics& other);

    //Деструктор
    ~Mathematics();

    //Методы

    //Проверка принадлежности элемента множеству
    bool Belonging(int value) const;

    //Операции

    //Добавление элемента в множество (+, +=);
    Mathematics operator+(int value) const;

    //Удаление элемента (-, -=);
    Mathematics operator-(int value) const;

    //Объединение двух множеств (+, +=);
    Mathematics operator+(const Mathematics& other) const;

    //Пересечение множеств (*, *=);
    Mathematics operator*(const Mathematics& other) const;

    //Cравнения множеств (==);
    bool operator==(const Mathematics& other) const;
};