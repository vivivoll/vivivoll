#include <iostream>
#include "fraction.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    //Объект с параметрами
    Fraction a(5,5);
    //Объект по умолчанию
    Fraction b(2,2);

    //Вывод дробей
    a.getFraction();
    cout << endl;
    b.getFraction();
    cout << endl;

    //Сложение
    a.plus(b);
    cout << "a + b = ";
    a.getFraction();

    cout << endl;

    //Вычитание
    a.minus(b);
    cout << "a - b = "; 
    a.getFraction();

    cout << endl;

    //Умножение
    a.multi(b);
    cout << "a * b = ";
    a.getFraction();

    cout << endl;

    a.div(b);
    cout << "a / b = ";
    a.getFraction();

    return 0;
}
