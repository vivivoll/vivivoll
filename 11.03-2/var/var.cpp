#include "var.h"
#include <iostream>
#include <string>

using namespace std;

//Конструктор без параметров 
var::var() {
    type = EMPTY;      
    i_val = 0;
    d_val = 0.0;
    s_val = "";
}

//Конструктор для целого числа
var::var(int v) {
    type = INT;        
    i_val = v;         
    d_val = 0.0;       
    s_val = "";
}

//Конструктор для вещественного числа
var::var(double v) {
    type = DOUBLE;
    d_val = v;
    i_val = 0;
    s_val = "";
}

//Конструктор для строки 
var::var(const string& v) {
    type = STRING;
    s_val = v;
    i_val = 0;
    d_val = 0.0;
}

//Арифметические операторы
var var::operator+(const var& other) const {
    var res = *this;
    res += other;
    return res;
}

var var::operator-(const var& other) const {
    var res = *this;
    res -= other;
    return res;
}

var var::operator*(const var& other) const {
    var res = *this;
    res *= other;
    return res;
}

var var::operator/(const var& other) const {
    var res = *this;
    res /= other;
    return res;
}

//+= 
var& var::operator+=(const var& other) {
    if (type == EMPTY) {
        *this = other;
        return *this;
    }
    if (other.type == EMPTY) {
        return *this;
    }

    if (type == INT && other.type == INT) {
        i_val += other.i_val;
    }
    else if (type == DOUBLE && other.type == DOUBLE) {
        d_val += other.d_val;
    }
    else if (type == STRING && other.type == STRING) {
        s_val += other.s_val;
    }

    return *this;
}

//-=
var& var::operator-=(const var& other) {
    if (type == EMPTY || other.type == EMPTY) {
        return *this;
    }

    if (type == INT && other.type == INT) {
        i_val -= other.i_val;
    }
    else if (type == DOUBLE && other.type == DOUBLE) {
        d_val -= other.d_val;
    }

    return *this;
}

//*=
var& var::operator*=(const var& other) {
    if (type == EMPTY || other.type == EMPTY) {
        return *this;
    }

    if (type == INT && other.type == INT) {
        i_val *= other.i_val;
    }
    else if (type == DOUBLE && other.type == DOUBLE) {
        d_val *= other.d_val;
    }

    return *this;
}

///= 
var& var::operator/=(const var& other) {
    if (type == EMPTY || other.type == EMPTY) {
        return *this;
    }

    if (type == INT && other.type == INT) {
        if (other.i_val != 0) {
            i_val /= other.i_val;
        }
        // на 0 не делим — ничего не меняем
    }
    else if (type == DOUBLE && other.type == DOUBLE) {
        if (other.d_val != 0.0) {
            d_val /= other.d_val;
        }
    }

    return *this;
}

//Операторы сравнения
//==
bool var::operator==(const var& other) const {
    if (type != other.type) return false;
    if (type == INT)    return i_val == other.i_val;
    if (type == DOUBLE) return d_val == other.d_val;
    if (type == STRING) return s_val == other.s_val;
    return true;
}

//!=
bool var::operator!=(const var& other) const { return !(*this == other); }

//<
bool var::operator<(const var& other) const {
    if (type != other.type) return false;

    if (type == INT)    return i_val < other.i_val;
    if (type == DOUBLE) return d_val < other.d_val;
    if (type == STRING) return s_val < other.s_val;
    return false;
}

//>
bool var::operator>(const var& other) const {
    if (type != other.type) return false;

    if (type == INT)    return i_val > other.i_val;
    if (type == DOUBLE) return d_val > other.d_val;
    if (type == STRING) return s_val > other.s_val;
    return false;
}

//<=
bool var::operator<=(const var& other) const { return !(*this > other); }

//>=
bool var::operator>=(const var& other) const { return !(*this < other); }

//Методы
//Вывод
void var::show() const {
    if (type == INT) {
        cout << i_val;
    } else if (type == DOUBLE) {
        cout << d_val;
    } else if (type == STRING) {
        cout << s_val;
    } else {
        cout << "Пусто";
    }
}