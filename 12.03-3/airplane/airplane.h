#pragma once
#include <iostream>
#include <string>
using namespace std;

class Airplane{
private:
    string type;
    int passengers;
    int maxPassengers;

public:

    //Конструктор по умолчанию
    Airplane();
    //Конструктор с параметрами
    Airplane(string t, int MaxP);

    //Методы
    //Вывод самолета
    void Print() const;

    //Геттеры
    int getPassengers() const;
    int getMaxPassengers() const;
    string getType() const;

    //Перегрузки
    //Оператор == 
    bool operator==(const Airplane& other) const;

    //Оператор ++ и --
    Airplane& operator++();
    Airplane& operator--();

    //Оператор >
    bool operator>(const Airplane& other) const;
};

