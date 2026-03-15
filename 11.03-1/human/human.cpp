#include "human.h"
#include <iostream>
#include <cstring>
using namespace std;

//Вспомогательная функция копирования строки
void copyString(char*& dest, const char* src) {
    delete[] dest;

    if (src == nullptr || src[0] == '\0') {
        dest = new char[1];
        dest[0] = '\0';
        return;
    }

    size_t len = strlen(src);
    dest = new char[len + 1];
    strcpy(dest, src);
}

//Конструктор по умолчанию
Human::Human() : FIO(nullptr), age(0) {
    copyString(FIO, "Неизвестно");
}

//Конструктор с параметрами
Human::Human(const char* fio, int a) : age(a), FIO(nullptr) {
    copyString(FIO, fio);
}

//Конструктор копирования
Human::Human(const Human& other) : age(other.age), FIO(nullptr) {
    copyString(FIO, other.FIO);
}

//Деконструктор
Human::~Human() {
    delete[] FIO;
}

//Методы
//Вывод информации
void Human::Print() const {
    cout << "ФИО: " << getFIO()
         << ", возраст: " << age << " лет" << endl;
}

//Геттеры
const char* Human::getFIO() const {
    if (FIO) {
        return FIO;
    }
    return "";
}

int Human::getAge() const {
    return age;
}

//Сеттеры
void Human::setFIO(const char* newFIO) {
    copyString(FIO, newFIO);
}

void Human::setAge(int newAge) {
    age = newAge;
}