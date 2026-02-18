#pragma once
#include <iostream>
using namespace std;

//Класс Дробь
class Fraction {
private:
	int numerator;
	int denominator;
	//Счетчик
	static int count;

public:
	//Конструктор по умолчанию
	Fraction();

	//Конструктор с параметрами
	Fraction(int numerator, int denominator);

	//Конструктор копирования
	Fraction(const Fraction& other);

	//Деструктор
	~Fraction();

	//Геттеры
	int getNumerator() const;
	int getDenominator() const;

	//Сеттеры
	void setNumerator(int num);
	void setDenominator(int den);

	//Методы

	//Вывод счетчика
	static int getCount();

	//Вывод дроби
	void getFraction();

	//Сложение
	void plus(const Fraction& other);
	//Вычитание 
	void minus(const Fraction& other);
	//Умножение
	void multi(const Fraction& other);
	//Деление
	void div(const Fraction& other);
};