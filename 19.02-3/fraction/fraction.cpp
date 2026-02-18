#include <iostream>
#include "fraction.h"
using namespace std;

//Инициализация счетчика 
int Fraction::count = 0;

//Конструктор по умолчанию
Fraction::Fraction() {
	this->numerator = 1;
	this->denominator = 1;
	count++;
}

//Конструктор с параметрами
Fraction::Fraction(int numerator, int denominator) {
	this->numerator = numerator;
	this->denominator = denominator;
	count++;
}

//Конструктор копирования
Fraction::Fraction(const Fraction& other) {
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	count++;
}

//Деструктор
Fraction::~Fraction() {
	count--;
}

//Геттеры
int Fraction::getNumerator() const { return numerator; }
int Fraction::getDenominator() const { return denominator; }

//Сеттеры
void Fraction::setNumerator(int num) { numerator = num; }
void Fraction::setDenominator(int den) { denominator = den; }

//Методы

//Вывод счетчика
int Fraction::getCount() {
	return count;
}

//Вывод Дроби
void Fraction::getFraction() {
	cout << numerator << "/" << denominator;
}

//Сложение
void Fraction::plus(const Fraction& other) {
	int new_numerator = numerator * other.denominator + other.numerator * denominator;
	int new_denominator = denominator * other.denominator;
	numerator = new_numerator;
	denominator = new_denominator;
}

//Вычитание
void Fraction::minus(const Fraction& other) {
	int new_numerator = numerator * other.denominator - other.numerator * denominator;
	int new_denominator = denominator * other.denominator;
	numerator = new_numerator;
	denominator = new_denominator;
	
}

//Умножение
void Fraction::multi(const Fraction& other) {
	int new_numerator = numerator * other.numerator;
	int new_denominator = denominator * other.denominator;
	numerator = new_numerator;
	denominator = new_denominator;
}

//Деление
void Fraction::div(const Fraction& other) {
	int new_numerator = numerator * other.denominator;
	int new_denominator = denominator * other.numerator;
	numerator = new_numerator;
	denominator = new_denominator;
}