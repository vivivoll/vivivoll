#include <iostream>
#include "dynamic.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    StringHolder* s1 = new StringHolder("Hello");
    StringHolder* s2 = new ReverseString("Hi");

    cout << "Обычная строка: ";
    s1->print();

    cout << "Перевёрнутая строка: ";
    s2->print();

    cout << "Удаление" << endl;
    delete s1;
    delete s2;

    return 0;
}