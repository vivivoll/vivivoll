#include <iostream>
#include "point.h"
using namespace std;

//ћетоды

	//¬вод x
void Point::InputX() {
	cout << "¬ведите x: ";
	cin >> x;
	cin.ignore();
}
//¬вод y
void Point::InputY() {
	cout << "¬ведите y: ";
	cin >> y;
	cin.ignore();
}
//¬вод z
void Point::InputZ() {
	cout << "¬ведите z: ";
	cin >> z;
	cin.ignore();
}
//¬ывод координат
void Point::OutputCoordinate() {
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;
}