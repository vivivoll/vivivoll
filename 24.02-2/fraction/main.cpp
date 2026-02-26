#include "fraction.h"
#include <iostream>

using namespace std;

//ввод числителя
void Fraction::InputNumerator() {
    cout << "Введите числитель: ";
    cin >> numerator;
}

//ввод знаменателя
void Fraction::InputDenominator() {
    cout << "Введите знаменатель: ";
    cin >> denominator;
}

//вывод дроби
void Fraction::Print() const {
    if (denominator == 1.0f) {
        cout << numerator;
    }
    else {
        cout << numerator << "/" << denominator;
    }
}

//сложение 
void Fraction::Plus() const {
    cout << "Сложение: ";
    Print();
    cout << " + " << numerator << "/" << denominator << " = ";
    cout << (numerator + denominator) << "/" << denominator << endl;
}

//вычитание
void Fraction::Minus() const {
    cout << "Вычитание: ";
    Print();
    cout << " - " << numerator << "/" << denominator << " = ";
    cout << (numerator - denominator) << "/" << denominator << endl;
}

//умножение
void Fraction::Multiplication() const {
    cout << "Умножение: ";
    Print();
    cout << " * " << numerator << "/" << denominator << " = ";
    cout << (numerator * numerator) << "/" << (denominator * denominator) << endl;
}

//деление
void Fraction::Division() const {
    cout << "Деление:   ";
    Print();
    cout << " / " << numerator << "/" << denominator << " = ";
}