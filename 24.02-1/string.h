#pragma once
#include <iostream>
#include <string>

using namespace std;

//Класс строки
class String {
private:
	//Хранение символов
	string data;
	//Статический счетчик
	static int count;
public:
	//Конструктор по умолчанию 80 строк
	String();
	String(int size);
	String(const char* text);
	//Деструктор
	~String();
	//Методы
	void input();
	void output() const;
	static int getCount();
};