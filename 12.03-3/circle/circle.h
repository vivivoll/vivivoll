#pragma once
#include <iostream>
using namespace std;

class Circle{
private:
    double radius;

public:
    //Конструктор по умолчанию 
    Circle();

    //Конструктор с параметрами
    Circle(double r);

    //Методы
    //Вывод радиуса
    void Print() const;

    //Перегрузки
    //Проверка на равенство радиусов двух окружностей
    bool operator==(const Circle& other) const;

    //Сравнения длин двух окружностей
    bool operator>(const Circle& other) const;

    //Оператор +
    Circle& operator+=(double value);

    //Оператор -
    Circle& operator-=(double value);

    //Геттер радиуса
    double getRadius() const;
};