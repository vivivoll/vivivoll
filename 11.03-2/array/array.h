#pragma once
using namespace std;

class Array{
private:
    int* data;
    int size;

public:
    //Конструктор по умолчанию
    Array();

    //Конструктор с параметрами
    Array(int n, int s = 0);

    //Конструктор копирования
    Array(const Array& other);

    //Дестркутор
    ~Array();

    //Оператор []
    int& operator[](int index);
  
    //Оператор ()
    void operator()(int value);

    //Методы
    //Вывод массива
    void Print() const;
};