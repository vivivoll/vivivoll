#include <iostream>
#include <string>
#include "airplane.h"
using namespace std;

//Конструктор по умолчанию
Airplane::Airplane(){
    type = "Неизвестный";
    passengers = 0;
    maxPassengers = 0;
}

//Конструктор с параметрами
Airplane::Airplane(string t, int MaxP){
    type = t;
    passengers = 0;
    maxPassengers = (MaxP > 0) ? MaxP : 0;
}

//Методы
//Вывод самолета
void Airplane::Print()const{
    cout << "Тип: " << type << endl;
    cout << "Пассажиры: " << passengers << endl;
    cout << "Максимальное количество: " << maxPassengers << endl;
}

//Геттеры
string Airplane::getType() const{
    return type;
}

int Airplane::getPassengers() const{
    return passengers;
}

int Airplane::getMaxPassengers() const{
    return maxPassengers;
}

//Перегрузки
//Оператор ==
bool Airplane::operator==(const Airplane& other) const{
    return type == other.type;
} 

//Оператор ++ и --
Airplane& Airplane::operator++(){
    if(passengers < maxPassengers){
        passengers++;
    }
    return *this;
}

Airplane& Airplane::operator--(){
    if(passengers > 0){
        passengers--;
    }
    return *this;
}

//Оператор >
bool Airplane::operator>(const Airplane& other) const{
    return maxPassengers > other.maxPassengers;
}