#include <iostream>
#include <string>
#include <stdexcept>
#include "Geometry.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");
    //площадь круга с радиусом
    cout << Geometry::circleArea(6.7);
    //площадь прямоугольника с сторонами
    cout << Geometry::rectangleArea(4.5, 2.0);
    //создание объекта
    Geometry::Shapes::Circle cir(4.0);
    cout << cir.area();

    return 0;
}