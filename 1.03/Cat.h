#pragma once
#include <iostream>
#include <string>

using namespace std;

//Базовый класс Cat
class Cat{
protected:
    string name;
    int age;
    string color;

public:
    //Конструктор с полями
    Cat(const string& name, int age, const string& color);
    
    //Методы
    void printInfo() const;

    //Геттеры
    string GetName() const { return name; }
    int GetAge() const { return age; }
    string GetColor() const { return color; }

    //Деструктор
    ~Cat();
};

//Произодный класс HouseCat
class HouseCat : public Cat{
private:
    string ownerName;

public:
    //Конструктор с параметрами
    HouseCat(const string& name, int age, const string& color, const string& ownerName);

    //Методы HouseCat
    void sound() const;

    void printInfo() const;

    //Деконструктор
    ~HouseCat();
};

//Произодный класс WildCat
class WildCat : public Cat{
private:
    string habibat;

public:

    //Конструктор с параметрами
    WildCat(const string& name, int age, const string& color, const string& habibat);

    //Методы
    void sound() const;
    void printInfo() const;

    //Деструктор 
    ~WildCat();
};

//Произодный класс PersianCat
class PersianCat : public Cat{
private:
    int woolLength;

public:
    //Конструктор с параметрами
    PersianCat(const string& name, int age, const string& color, int woolLength);

    //Методы
    void sound() const;
    void printInfo() const;
    void groom() const;

    //Деконструктор
    ~PersianCat();
};