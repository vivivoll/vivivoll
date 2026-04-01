#include <iostream>
#include <cstring>
#include "dynamic.h"
using namespace std;

//Конструктор
StringHolder::StringHolder(const char* s) {
    if (s == nullptr) {
        str = new char[1];
        str[0] = '\0';
    } else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

//Виртуальный деструктор
StringHolder::~StringHolder() {
    cout << "Деструктор StringHolder\n";
    delete[] str;
}

//Виртуальный метод вывода
void StringHolder::print() const {
    cout << str << endl;
}
/////////////////////////////

//Конструктор
ReverseString::ReverseString(const char* s) : StringHolder(s) {}

//Метод вывода
void ReverseString::print() const {
    if (str == nullptr) {
        cout << endl;
        return;
    }
    for (int i = strlen(str) - 1; i >= 0; --i) {
        cout << str[i];
    }
    cout << endl;
}