#include <iostream>
#include <string>
#include "string.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	//Создание объекта
	String str_1;
	//Ввод строки
	cout << "Ввод строки";
	str_1.input();
	cout << endl;
	//Вывод строки
	str_1.output();
	cout << endl;
	//Вывод кол-ва объектов
	cout << "Кол-во объектов: " << String::getCount();

	return 0;
}