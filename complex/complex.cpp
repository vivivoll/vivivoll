#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    //конструкторы
    Complex() : real(0.0), imag(0.0) {}
    Complex(double r, double i) : real(r), imag(i) {}
    Complex(double r) : real(r), imag(0.0) {}

    //методы для получения значения
    double getReal() const { return real; }
    double getImag() const { return imag; }

    //перегрузка операторов через методы класса
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator-() const {
        return Complex(-real, -imag);
    }

    //перегрузка оператора вызова функции ()
    Complex operator()(double r, double i) {
        real = r;
        imag = i;
        return *this;
    }

    //функции для ввода/вывода и сравнения
    friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is, Complex& c);
    friend bool operator==(const Complex& a, const Complex& b);
    friend bool operator!=(const Complex& a, const Complex& b);
};

//перегрузка вывода <<
ostream& operator<<(ostream& os, const Complex& c) {
    setlocale(LC_ALL, "ru");
    os << c.real;
    if (c.imag >= 0)
        os << "+" << c.imag << "i";
    else
        os << c.imag << "i";
    return os;
}

//перегрузка ввода >>
istream& operator>>(istream& is, Complex& c) {
    cout << "Введите действительную часть: ";
    is >> c.real;
    cout << "Введите мнимую часть: ";
    is >> c.imag;
    return is;
}

//перегрузка оператора ==
bool operator==(const Complex& a, const Complex& b) {
    return (a.real == b.real) && (a.imag == b.imag);
}

//перегрузка оператора !=
bool operator!=(const Complex& a, const Complex& b) {
    return !(a == b);
}

//пример
int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "c1 + c2 = " << sum << endl;
    cout << "c1 - c2 = " << diff << endl;

    if (c1 == c2) {
        cout << "c1 и c2 равны" << endl;
    }
    else {
        cout << "c1 и c2 не равны" << endl;
    }

    c1(5, 6);
    cout << "После c1(5, 6): c1 = " << c1 << endl;

    //ввод
    Complex c3;
    cin >> c3;
    cout << "Вы ввели: " << c3 << endl;

    return 0;
}