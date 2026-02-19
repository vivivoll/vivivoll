#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    char* name; //динамическая память
    string date;
    string phone;
    string city;
    string country;
    string name_study;
    string city_study;
    string country_study;
    int number;

    //копирования строки
    void copyString(char*& dest, const char* src);

public:
    //конструкторы
    Student();
    Student(const char* n);

    //деструктор
    ~Student();

    //геттеры
    string getName() const;
    int    getNumber() const;

    //сеттеры
    void setName(const string& s);
    void setNumber(int n);

    //методы вывода
    string OutputName()        const;
    string OutputDate()        const;
    string OutputPhone()       const;
    string OutputCity()        const;
    string OutputCountry()     const;
    string OutputNameStudy()   const;
    string OutputCityStudy()   const;
    string OutputCountryStudy() const;
    int    OutputNumber()      const;

    //методы ввода 
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