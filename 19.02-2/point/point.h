#pragma once
#include <iostream>
using namespace std;

//Класс точка
class Point {
public:
	//Атрибуты
	int x;
	int y;
	int z;

	//Методы

	//Ввод x
	void InputX(); 

	//Ввод y
	void InputY();

	//Ввод z
	void InputZ();

	//Вывод координат
	void OutputCoordinate();
};