#include <iostream>
#include "geometry.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	//Вычисления фигур
	cout << "Площадь прямоугольника 5 * 6 = " << Geometry::rectangle(5, 6) << endl;
	cout << endl;
	cout << "Площадь квадрата со стороной 5 = " << Geometry::square(5) << endl;
	cout << endl;
	cout << "Площадь ромба со стороной 5 и высотой 8 = " << Geometry::rhombus_1(5, 8) << endl;
	cout << endl;
	cout << "Площадь ромба с диагональю 3 и 6 = " << Geometry::rhombus_2(3, 6) << endl;
	cout << endl;
	cout << "Площадь треугольника с основанием 34 и высотой 36 = " << Geometry::rhombus_2(34, 36) << endl;
	cout << endl;
	cout << "Площадь треугольника  со сторонами 4, 5, 7 = " << Geometry::triangle_2(4, 5, 7) << endl;
	cout << endl;
	//Подсчет всех вычислений
	cout << "Всего подсчетов: " << Geometry::calculatorCount();

	return 0;
}