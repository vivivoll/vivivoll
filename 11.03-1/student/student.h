#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    char* name; //Имя
    string date;
    string phone;
    string city;
    string country;
    string name_study;
    string city_study;
    string country_study;
    int number;

    //Функция копирования
    void copyString(char*& dest, const char* src);

public:
    //Конструкторы
    Student();
    Student(const char* n);

    //Конструктор перемещения
    Student(const Student& other) noexcept;

    //Деконструктор
    ~Student();

    //Геттеры
    string getName() const;
    int    getNumber() const;

    //Сеттеры
    void setName(const string& s);
    void setNumber(int n);

    //Метод ввода
    string OutputName()        const;
    string OutputDate()        const;
    string OutputPhone()       const;
    string OutputCity()        const;
    string OutputCountry()     const;
    string OutputNameStudy()   const;
    string OutputCityStudy()   const;
    string OutputCountryStudy() const;
    int    OutputNumber()      const;

    //Метод вывода
    string InputName();
    string InputDate();
    string InputPhone();
    string InputCity();
    string InputCountry();
    string InputNameStudy();
    string InputCityName();
    string InputCountryStudy();
    int    InputNumber();
};