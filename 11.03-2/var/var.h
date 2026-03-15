#pragma once
#include <iostream>
#include <string>
using namespace std;

class var {
private:
    //Enum типов данных
    enum Type{ 
        INT, 
        DOUBLE, 
        STRING, 
        EMPTY 
    };

    Type type = EMPTY;
    int i_val = 0;
    double d_val = 0.0;
    string s_val;

public:
    //Конструкторы
    var();
    var(int v);
    var(double v);
    var(const std::string& v);
    var(const char* v);

    //Арифметические операторы
    var operator+(const var& other) const;
    var operator-(const var& other) const;
    var operator*(const var& other) const;
    var operator/(const var& other) const;

    var& operator+=(const var& other);
    var& operator-=(const var& other);
    var& operator*=(const var& other);
    var& operator/=(const var& other);

    //Операторы сравнения
    bool operator==(const var& other) const;
    bool operator!=(const var& other) const;
    bool operator<(const var& other) const;
    bool operator>(const var& other) const;
    bool operator<=(const var& other) const;
    bool operator>=(const var& other) const;

    //Методы
    //Вывод
    void show() const;
};