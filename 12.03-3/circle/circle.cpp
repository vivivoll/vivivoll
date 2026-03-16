#include <iostream>
#include "circle.h"
using namespace std;

//Конструктор по умолчанию 
Circle::Circle(){
    radius = 0.0;
}

//Конструктор с параметрами
Circle::Circle(double r){
    if(r > 0){
        radius = r;
    }
    else{
        radius = 0;
    }
}

//Вывод радиуса
void Circle::Print() const{
    cout << "Радиус: " << radius << endl;
}

//Перегрузки
//Проверка на равенство радиусов двух окружностей
bool Circle::operator==(const Circle& other) const{
    return radius == other.radius;
}

//Сравнения длин двух окружностей
bool Circle::operator>(const Circle& other) const{
    return radius > other.radius;
}

//Оператор +
Circle& Circle::operator+=(double value){
    radius += value;
}

//Оператор -
Circle& Circle::operator-=(double value){
    radius -= value;
}

//Геттер радиуса
double Circle::getRadius() const{
    return radius;
}