#pragma once
#include <iostream>
#include <string>
using namespace std;

//Класс Человек
class Human {
private:
	int id;
	string second_name;
	string name;
	string third_name;
	string date_birthday;
	//Счетчик для объектов
	static int count;
public:
	//Конструктор по умолчанию
	Human();

	//Конструктор с параметрами
	Human(int id, string second_name, string name, string third_name, string date_birthday);

	//Конструктор копирования
	Human(const Human& other);

	//Деструктор
	~Human();

	//Геттеры
	int getId() const { return id; }
	string getSecondName() const { return second_name; }
	string getName() const { return name; }
	string getThirdName() const { return third_name; }
	string getDateBirthday() const { return date_birthday; }

	//Сеттеры
	void setId(int i) { id = i; }
	void setSecondName(string s) { second_name = s; }
	void setName(string n) { name = n; }
	void setThirdName(string t) { third_name = t; }
	void setDateBirthday(string d) { date_birthday = d; }

	//Методы
	//Вывод счетчика
	int getCount();

	//Ввод данных о человеке
	void inputHuman();

	//Вывод данных о человеке
	void outputHuman();
};