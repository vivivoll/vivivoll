#include <iostream>
#include "InitArray.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    cout << "Создание массива" << endl;
    IntArray a(5);
    a.print();

    cout << "Копирование" << endl;
    IntArray b = a;
    b.print();

    cout << "Перемещение" << endl;
    IntArray c = IntArray(3);
    c.print();

    cout << "Перемещение через move" << endl;
    IntArray d = move(a);
    d.print();

    cout << "Присваивание копированием" << endl;
    IntArray e(2);
    e = b;
    e.print();

    cout << "Присваивание перемещением" << endl;
    IntArray f(1);
    f = move(c);
    f.print();

    return 0;
}