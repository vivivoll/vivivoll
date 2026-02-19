#pragma once
#include <iostream>

class Fraction {
private:
    float numerator;   //числитель
    float denominator; //знаменатель

public:
    //конструктор по умолчанию
    Fraction() : numerator(0.0f), denominator(1.0f) {}

    //конструктор с параметрами
    Fraction(float num, float den)
        : numerator(num), denominator(den != 0 ? den : 1.0f) {}

    //геттеры 
    inline float getNumerator()   const { return numerator; }
    inline float getDenominator() const { return denominator; }

    //сеттеры 
    inline void setNumerator(float num) { numerator = num; }
    inline void setDenominator(float den)
    {
        denominator = (den != 0) ? den : 1.0f;
    }

    //методы ввода 
    void InputNumerator();
    void InputDenominator();

    //методы операций 
    void Plus()     const;
    void Minus()    const;
    void Multiplication() const;
    void Division() const;

    //вывод дроби 
    void Print() const;
};