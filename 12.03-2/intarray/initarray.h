#pragma once
#include <iostream>
using namespace std;

class IntArray{
private:
    int* data;      //Динамический массив
    size_t size;    //Количество объектов

public:
    //Конструктор по умолчанию
    IntArray();

    //Конструктор от size_t
    IntArray(size_t n);

    //Конструктор копирования
    IntArray(const IntArray& other);

    //Конструктор перемещения
    IntArray(IntArray&& other);

    //Деструктор
    ~IntArray();

    //Оператор присваивания копированием
    IntArray& operator=(const IntArray& other);

    //Оператор присваивания перемещением
    IntArray& operator=(IntArray&& other);
    
    //Метод print
    void print() const;


};