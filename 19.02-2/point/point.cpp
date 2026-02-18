#include <iostream>
#include "point.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");

	//Объект
	Point point_1;

	cout << "Ввод координат" << endl;
	point_1.InputX();
	point_1.InputY();
	point_1.InputZ();
	cout << endl;

	cout << "Вывод координат" << endl;
	point_1.OutputCoordinate();

	return 0;
}