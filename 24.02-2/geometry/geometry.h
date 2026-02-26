#pragma once
#include <iostream>

//Класс геометрические фигуры
class Geometry {
private:
	//Статический счетчик
	static int count;
public:
	//Подсчет счетчика
	static int calculatorCount(); 
	//Прямоугольник
	static double rectangle(double length, double width);
	//Квадрат
	static double square(double length);
	//Ромб 1 вариант
	static double rhombus_1(double side, double heigth);
	//Ромб 2 вариант
	static double rhombus_2(double diagonal_1, double diagonal_2);
	//Треугольник 1 вариант
	static double triangle_1(double base, double heigth);
	//Треугольник 2 вариант
	static double triangle_2(double a, double b, double c);
};