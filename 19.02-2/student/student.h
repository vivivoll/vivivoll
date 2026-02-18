#pragma once
#include <iostream>
#include <string>
using namespace std;

//Класс Студент
class Student {
public:
	//Атрибуты
	string name;
	string date;
	string phone;
	string city;
	string country;
	string name_study;
	string city_study;
	string country_study;
	int number;

	//Методы

	//Ввод имени
	string InputName();

	//Ввод даты рождения
	string InputDate();

	//Ввод номера телефона
	string InputPhone();

	//Ввод города
	string InputCity();

	//Ввод страны
	string InputCountry();

	//Ввод имени учебного заведения
	string InputNameStudy();

	//Ввод города, где учебное заведение
	string InputCityName();

	//Ввод страны, где учебное заведение
	string InputCountryStudy();

	//Ввод номера группы
	int InputNumber();

	//Вывод имени
	string OutputName();

	//Вывод даты рождения
	string OutputDate();

	//Вывод номера телефона
	string OutputPhone();

	//Вывод города
	string OutputCity();

	//Вывод страны
	string OutputCountry();

	//Вывод имени учебного заведения
	string OutputNameStudy();

	//Вывод города, где учебное заведение
	string OutputCityStudy();

	//Вывод страны, где учебное заведение
	string OutputCountryStudy();

	//Вывод номер группы
	int OutputNumber();
};

