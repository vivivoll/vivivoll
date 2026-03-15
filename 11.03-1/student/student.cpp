#include <iostream>
#include <string>
#include <cstring>
#include "student.h"
using namespace std;

//Вспомогательная функция копирования строки
void Student::copyString(char*& dest, const char* src) {
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

// Конструкторы и деструктор
Student::Student()
    : name(nullptr), date(""), phone(""), city(""), country(""),
    name_study(""), city_study(""), country_study(""), number(0)
{
    copyString(name, "Неизвестно");
}

Student::Student(const char* n)
    : name(nullptr), date(""), phone(""), city(""), country(""),
    name_study(""), city_study(""), country_study(""), number(0)
{
    copyString(name, n);
}


//Конструктор перемещения
Student::Student(const Student& other) noexcept{
    //Функция копирования
    copyString(name, other.name);

    name = other.name;
    number = other.number;
    date = other.date;
    phone = other.phone;
    city = other.city;
    country = other.country;
    name_study = other.name_study;
    city_study = other.city_study;
    country_study = other.country_study;
}


Student::~Student() {
    delete[] name;
}

// Геттеры и сеттеры 
string Student::getName() const {
    if (name) {
        return string(name);
    }
    return "";
}

int Student::getNumber() const {
    return number;
}

void Student::setName(const string& s) {
    copyString(name, s.c_str());
}

void Student::setNumber(int n) {
    number = n;
}

// Методы вывода
string Student::OutputName() const {
    return getName();
}

string Student::OutputDate() const {
    return date;
}

string Student::OutputPhone() const {
    return phone;
}

string Student::OutputCity() const {
    return city;
}

string Student::OutputCountry() const {
    return country;
}

string Student::OutputNameStudy() const {
    return name_study;
}

string Student::OutputCityStudy() const {
    return city_study;
}

string Student::OutputCountryStudy() const {
    return country_study;
}

int Student::OutputNumber() const {
    return number;
}

// Методы ввода (без изменений)
string Student::InputName() {
    string input;
    cout << "Введите ФИО (Иванов Иван Иванович): ";
    getline(cin, input);
    setName(input);
    return input;
}

string Student::InputDate() {
    string input;
    cout << "Введите дату рождения (XX.XX.XXXX): ";
    getline(cin, input);
    date = input;
    return input;
}

string Student::InputPhone() {
    string input;
    cout << "Введите номер телефона (+7 XXX XXX XX XX): ";
    getline(cin, input);
    phone = input;
    return input;
}

string Student::InputCity() {
    string input;
    cout << "Введите город: ";
    getline(cin, input);
    city = input;
    return input;
}

string Student::InputCountry() {
    string input;
    cout << "Введите страну: ";
    getline(cin, input);
    country = input;
    return input;
}

string Student::InputNameStudy() {
    string input;
    cout << "Введите имя учебного заведения: ";
    getline(cin, input);
    name_study = input;
    return input;
}

string Student::InputCityName() {
    string input;
    cout << "Введите город, где находится учебное заведение: ";
    getline(cin, input);
    city_study = input;
    return input;
}

string Student::InputCountryStudy() {
    string input;
    cout << "Введите страну, где находится учебное заведение: ";
    getline(cin, input);
    country_study = input;
    return input;
}

int Student::InputNumber() {
    cout << "Введите номер группы: ";
    cin >> number;
    cin.ignore();  //очищаем буфер после числа
    return number;
}