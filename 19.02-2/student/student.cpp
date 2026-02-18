#include <iostream>
#include <string>
#include "student.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");

	//Объект
	Student student_1;

	cout << "Ввод данных о студенте" << endl;
	cout << student_1.InputName() << endl;
	cout << student_1.InputDate() << endl;
	cout << student_1.InputPhone() << endl;
	cout << student_1.InputCity() << endl;
	cout << student_1.InputCountry() << endl;
	cout << student_1.InputNameStudy() << endl;
	cout << student_1.InputCityName() << endl;
	cout << student_1.InputCountryStudy() << endl;
	cout << student_1.InputNumber() << endl;
	cout << endl;
	cout << "Вывод данных о студенте" << endl;
	cout << student_1.OutputName() << endl;
	cout << student_1.OutputDate() << endl;
	cout << student_1.OutputPhone() << endl;
	cout << student_1.OutputCity() << endl;
	cout << student_1.OutputCountry() << endl;
	cout << student_1.OutputNameStudy() << endl;
	cout << student_1.OutputCityStudy() << endl;
	cout << student_1.OutputCountryStudy() << endl;
	cout << student_1.OutputNumber() << endl;

	return 0;
}