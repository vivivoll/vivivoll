#include "kvartira.h"
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
Kvartira::Kvartira() : address(nullptr), floor(0), people(0) {
    copyString(address, "Не указана");
}

//Конструктор с параметрами
Kvartira::Kvartira(const char* adr, int fl, int ppl)
    : address(nullptr), floor(fl), people(ppl)
{
    copyString(address, adr);
}

// Конструктор копирования
Kvartira::Kvartira(const Kvartira& other)
    : address(nullptr), floor(other.floor), people(other.people)
{
    copyString(address, other.address);
}

// Конструктор перемещения
Kvartira::Kvartira(Kvartira&& other) noexcept : 
    address(other.address),
    floor(other.floor),
    people(other.people){

    //Забираем у временного объекта
    other.address = nullptr;
    other.floor   = 0;
    other.people  = 0;
}


//Деконструктор 
Kvartira::~Kvartira() {
    delete[] address;
}

//Методы
//Вывод информации
void Kvartira::Print() const {
    cout << "Квартира: " << getAddress() << endl;
    cout << "Этаж: " << floor << endl;
    cout << "Проживает людей: " << people << endl;
}

//Геттеры
const char* Kvartira::getAddress() const {
    return address ? address : "";
}

int Kvartira::getFloor() const {
    return floor;
}

int Kvartira::getPeople() const {
    return people;
}

//Сеттеры
void Kvartira::setAddress(const char* newAddress) {
    copyString(address, newAddress);
}

void Kvartira::setFloor(int newFloor) {
    floor = newFloor;
}

void Kvartira::setPeople(int newPeople) {
    people = newPeople;
}