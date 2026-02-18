#include <iostream>
#include <string>
#include "human.h"
using namespace std;

//Инициализация счетчика объектов
int Human::count = 0;

//Конструктор по умолчанию
Human::Human() {
	this->id = 0;
	this->second_name = "";
	this->name = "";
	this->third_name = "";
	this->date_birthday = "";
	count++;
}

//Конструктор с параметрами
Human::Human(int id, string second_name, string name, string third_name, string date_birthday) {
	this->id = id;
	this->second_name = second_name;
	this->name = name;
	this->third_name = third_name;
	this->date_birthday = date_birthday;
	count++;
}

//Конструктор копирования 
Human::Human(const Human& other) {
	this->id = other.id;
	this->second_name = other.second_name;
	this->name = other.name;
	this->third_name = other.third_name;
	this->date_birthday = other.date_birthday;
	count++;
}

//Деструктор
Human::~Human() {
	count--;
}

//Методы
//Вывод счетчика
int Human::getCount() {
	return count;
}

//Ввод данных о человеке
void Human::inputHuman() {
	cout << "Введите id: ";
	cin >> id;
	cout << "Введите фамилию: ";
	cin >> second_name;
	cout << "Введите имя: ";
	cin >> name;
	cout << "Введите отчество: ";
	cin >> third_name;
	cout << "Введите дату рождения (xx.xx.xxxx): ";
	cin >> date_birthday;
}

void Human::outputHuman() {
	cout << "id: " << id << endl;
	cout << "Фамилия: " << second_name << endl;
	cout << "Имя: " << name << endl;
	cout << "Отчество: " << third_name << endl;
	cout << "Дата рождения: " << date_birthday << endl;
}