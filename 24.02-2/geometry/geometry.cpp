#include <iostream>
#include "geometry.h"
#include <cmath>

using namespace std;

//Инициализация счетчика
int Geometry::count = 0;

//Получение счетчика
int Geometry::calculatorCount() {
	return count;
}

//Прямоугольник
double Geometry::rectangle(double length, double width) {
	count++;
	return length * width;
}

//Квадрат
double Geometry::square(double length) {
	count++;
	return length * length;
}

//Ромб 1 вариант
double Geometry::rhombus_1(double side, double heigth) {
	count++;
	return side * heigth;
}

//Ромб 2 вариант
double Geometry::rhombus_2(double diagonal_1, double diagonal_2) {
	count++;
	return (diagonal_1 * diagonal_2) / 2.0;
}

//Треугольник 1 вариант
double Geometry::triangle_1(double base, double heigth) {
	count++;
	return (base * heigth) / 2.0;
}

//Треугольник 2 вариант
double Geometry::triangle_2(double a, double b, double c) {
	count++;
	double p = (a + b + c) / 2.0;
	return sqrt(p * (p - a) * (p * b) - (p * c));
}