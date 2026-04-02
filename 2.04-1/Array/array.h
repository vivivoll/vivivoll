#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class IntArray{
private:
    int* data; //Динамический массив
    int count; //Количество элементов

public:
    //Конструктор
    IntArray(int c, int* d);


    //Метод возврата элемента по индексу
    int at(int index);

    //Деструктор
    ~IntArray();
};