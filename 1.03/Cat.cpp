#include <iostream>
#include <string>
#include "Cat.h"

using namespace std;

//Конструктор с полями Cat
Cat::Cat(const string& name, int age, const string& color){
    this -> name = name;
    this -> age = age;
    this ->color = color;
}
//Метод вывода информации о кошке Cat
void Cat::printInfo() const{
    cout << "Имя: " << name << endl;
    cout << "Возраст: " << age << endl;
    cout << "Цвет: " << color << endl;
}
//Деструктор Cat
Cat::~Cat(){
    cout << "Cat: " << name << " destroyed" << endl;
}
//Конструктор с параметрами HouseCat
HouseCat::HouseCat(const string& name, int age, const string& color, const string& ownerName) : Cat(name, age, color){
    this -> ownerName = ownerName;
}
//Методы
void HouseCat::sound() const{
    cout << name << " purrs: Mrr-mrrr" << endl;
}

void HouseCat::printInfo() const {
    Cat::printInfo();
    cout << "Владелец: " << ownerName << endl;
}
//Деконструктор HouseCat
HouseCat::~HouseCat(){
    cout << "HouseCat: " << name << " destroyed" << endl;
}
//Конструктор с параметрами
WildCat::WildCat(const string& name, int age, const string& color, const string& habibat) : Cat(name, age, color){
    this -> habibat = habibat;
}
//Методы
void WildCat::sound() const{
    cout << name << " growls: Rrrr!" << endl;
}

void WildCat::printInfo() const{
    Cat::printInfo();
    cout << "Среда обитания: " << habibat << endl;
}
//Дектруктор
WildCat::~WildCat(){
    cout << "WildCat " << name << " destroyed" << endl; 
}
//Конструктор с параметрами
PersianCat::PersianCat(const string& name, int age, const string& color, int woolLength) : Cat(name, age, color){
    this -> woolLength = woolLength;
}
//Методы
void PersianCat::sound() const{
    cout << name << " says softly: Meow" << endl;
}

void PersianCat::printInfo() const{
    Cat::printInfo();
    cout << "Длина шерсти: " << woolLength << endl;
}

void PersianCat::groom() const{
    cout << name << " needs grooming" << endl;
}
//Деконструктор
PersianCat::~PersianCat(){
    cout << "PersianCat " << name << "destroyed" << endl;
}