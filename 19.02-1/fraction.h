#pragma once
#include <iostream>
using namespace std;

class Fraction {
public:
	//Атрибуты
	float numerator;
	float denominator;

	//Ввод числителя
	void InputNumerator();

	//Ввод знаменателя
	void InputDenominator();

	//Сложение
	void Plus();

	//Вычитание 
	void Minus();

	//Умножение
	void Multiplication();

	//Деление
	void Division();
};
