#include <iostream>
#include "fraction.h"

using namespace std;

	//Ввод числителя
void Fraction::InputNumerator() {
	cout << "Введите числитель: ";
	cin >> numerator;
}
//Ввод знаменателя
void Fraction::InputDenominator() {
	cout << "Введите знаменатель: ";
	cin >> denominator;
}
//Сложение
void Fraction::Plus() {
	cout << "Сложение: " << numerator + denominator << endl;
}
//Вычитание 
void Fraction::Minus() {
	cout << "Вычитание: " << numerator - denominator << endl;
}
//Умножение
void Fraction::Multiplication() {
	cout << "Умножение: " << numerator * denominator << endl;
}
//Деление
void Fraction::Division() {
	cout << "Деление: " << numerator / denominator << endl;
}