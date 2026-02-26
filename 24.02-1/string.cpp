#include <iostream>
#include <string>
#include "string.h"

using namespace std;

//Инициализация счетчика
int String::count = 0;

String::String(int size) {
	count++;
}
String::String() : String(80) {

}
String::String(const char* text) : String(80) {
	if (text != nullptr) {
		data = text;
	}
}
String::~String() {
	count--;
}
//Ввод 
void String::input() {
	string line;
	getline(cin, line);
	data = line;
}
// Вывод строки
void String::output() const {
	cout << data;
}
//Вывод количества объектов
int String::getCount() {
	return count;
}