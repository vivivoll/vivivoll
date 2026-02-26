#include <iostream>
#include "point.h"

using namespace std;

//ввод x
void Point::InputX() {
	cout << "Введите x: ";
	cin >> x;
	cin.ignore();
}
//ввод y
void Point::InputY() {
	cout << "Введите y: ";
	cin >> y;
	cin.ignore();
}
//ввод z
void Point::InputZ() {
	cout << "Введите z: ";
	cin >> z;
	cin.ignore();
}

//вывод координат
void Point::OutputCoordinate() const {
	cout << "Координаты точки: "
		<< "x = " << x
		<< ", y = " << y
		<< ", z = " << z << endl;
};