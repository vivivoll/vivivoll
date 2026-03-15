#include <iostream>
#include "var.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    //Объекты
    var a = 10;              //Целое 
    var b = 3.5;             //Вещественное 
    var s = "Привет";        //Cтрока

    cout << "Начальные значения:";
    a.show();
    b.show();
    s.show();

    cout << "Cложение" << endl;
    var sum1 = a + b;        
    sum1.show();

    var sum2 = s + b;      
    sum2.show();

    var sum3 = a + s;          
    sum3.show();

    cout << "Сравнение" << endl;
    if (a == 10) {
        cout << "a равно 10" << endl;
    } else {
        cout << "a не равно 10 — нет" << endl;
    }

    return 0;
}