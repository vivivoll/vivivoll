#include <iostream>
#include <string>
#include "student.h"
using namespace std;

//Методы
	//Ввод имени
string Student::InputName() {
	string input;
	cout << "Введите ФИО (Иванов Иван Иванович): ";
	getline(cin, input);
	name = input;
	return input;
}
//Ввод даты рождения
string Student::InputDate() {
	string input;
	cout << "Введите дату рождения(XX.XX.XXXX)";
	getline(cin, input);
	date = input;
	return input;
}
//Ввод номера телефона
string Student::InputPhone() {
	string input;
	cout << "Введите номер телефона (+7 XXX XXX XX XX): ";
	getline(cin, input);
	phone = input;
	return input;
}
//Ввод города
string Student::InputCity() {
	string input;
	cout << "Введите город: ";
	getline(cin, input);
	city = input;
	return input;
}
//Ввод страны
string Student::InputCountry() {
	string input;
	cout << "Введите страну: ";
	getline(cin, input);
	country = input;
	return input;
}
//Ввод имени учебного заведения
string Student::InputNameStudy() {
	string input;
	cout << "Введите имя учебного заведения: ";
	getline(cin, input);
	name_study = input;
	return input;
}
//Ввод города, где учебное заведение
string Student::InputCityName() {
	string input;
	cout << "Введите город, где находится учебное заведение: ";
	getline(cin, input);
	city_study = input;
	return input;
}
//Ввод страны, где учебное заведение
string Student::InputCountryStudy() {
	string input;
	cout << "Введите страну, где находится учебное заведение: ";
	getline(cin, input);
	country_study = input;
	return input;
}
//Ввод номера группы
int Student::InputNumber() {
	cout << "Введите номер группы: ";
	cin >> number;
	cin.ignore();
	return number;
}
//Вывод имени
string Student::OutputName() {
	return name;
}
//Вывод даты рождения
string Student::OutputDate() {
	return date;
}
//Вывод номера телефона
string Student::OutputPhone() {
	return phone;
}
//Вывод города
string Student::OutputCity() {
	return city;
}
//Вывод страны
string Student::OutputCountry() {
	return country;
}
//Вывод имени учебного заведения
string Student::OutputNameStudy() {
	return name_study;
}
//Вывод города, где учебное заведение
string Student::OutputCityStudy() {
	return city_study;
}
//Вывод страны, где учебное заведение
string Student::OutputCountryStudy() {
	return country_study;
}
//Вывод номер группы
int Student::OutputNumber() {
	return number;
}