#pragma once
#include <iostream>

using namespace std;

//класс точки
class Point {

private:
	//атрибуты
	int x;
	int y;
	int z;
public:
	//конструктор по умолчанию
	Point() : x(0), y(0), z(0) {}

	//конструктор с параметрами
	Point(int xx, int yy, int zz) : x(xx), y(yy), z(zz) {}

	//геттеры 
	inline int getX() const { return x; }
	inline int getY() const { return y; }
	inline int getZ() const { return z; }

	//сеттеры 
	inline void setX(int xx) { x = xx; }
	inline void setY(int yy) { y = yy; }
	inline void setZ(int zz) { z = zz; }

	//методы ввода
	void InputX();
	void InputY();
	void InputZ();

	//вывод координат
	void OutputCoordinate() const;
};