#include "house.h"
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
House::House() : address(nullptr), kvartira(0), people(0) {
    copyString(address, "Не указан");
}

//Конструктор с параметрами
House::House(const char* adr, int kv, int ppl)
    : address(nullptr), kvartira(kv), people(ppl)
{
    copyString(address, adr);
}

//Конструктор копирования
House::House(const House& other)
    : address(nullptr), kvartira(other.kvartira), people(other.people)
{
    copyString(address, other.address);
}

// Конструктор перемещения
House::House(House&& other) noexcept : 
    address(other.address),
    kvartira(other.kvartira),
    people(other.people) {
    //Забираем у предыдущего объекта
    other.address = nullptr;
    other.kvartira = 0;
    other.people   = 0;
}

//Деконструктор
House::~House() {
    delete[] address;
}

//Методы
//Вывод информации
void House::Print() const {
    cout << "Дом по адресу: " << getAddress() << endl;
    cout << "Количество квартир: " << kvartira << endl;
    cout << "Количество жителей: " << people << endl;
}

//Геттеры
const char* House::getAddress() const {
    return address ? address : "";
}

int House::getKvartira() const {
    return kvartira;
}

int House::getPeople() const {
    return people;
}

//Сеттеры
void House::setAddress(const char* newAddress) {
    copyString(address, newAddress);
}

void House::setKvartira(int newKvartira) {
    kvartira = newKvartira;
}

void House::setPeople(int newPeople) {
    people = newPeople;
}