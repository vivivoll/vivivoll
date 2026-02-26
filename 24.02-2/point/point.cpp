#include <iostream>
#include "point.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    //конструктор по умолчанию
    Point p1;
    cout << "Точка по умолчанию: ";
    p1.OutputCoordinate();
    cout << endl;

    //ввод с клавиатуры
    cout << "\nВведите координаты точки:\n";
    p1.InputX();
    p1.InputY();
    p1.InputZ();
    p1.OutputCoordinate();

    //конструктор с параметрами
    Point p2(5, -3, 8);
    cout << "Точка с параметрами" << endl;
    p2.OutputCoordinate();

    return 0;

}