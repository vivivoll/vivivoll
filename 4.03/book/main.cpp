#include <iostream>
#include <string>
#include "book.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	//Массив объектов
	Book book[3] = {
		Book("Пушкин", "Дубровский", "Первое", 1800, 200, 444),
		Book("Толстой", "Война и Мир", "Второе", 1750, 9999, 1000),
		Book("Достоевский", "Преступник и Наказание", "Третье", 1690, 800, 333)
	};
	
	//Вывод работы методов
	cout << "Список книг по автору" << endl;
	book[2].PrintBookFromAuthor(book, 3, "Достоевский");
	cout << endl;
	cout << "Список книг по издательству" << endl;
	book[2].PrintBookFromPublish(book, 3, "Первое");
	cout << endl;
	cout << "Список книг после заданного года" << endl;
	book[2].PrintBookFromYear(book, 3, 1700);
	cout << endl;
	

	return 0;
}
