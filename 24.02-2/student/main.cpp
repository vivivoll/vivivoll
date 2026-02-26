#include <iostream>
#include <string>
#include "student.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    Student main;

    cout << "Ввод данных о студенте" << endl;
    cout << main.InputName() << endl;
    cout << main.InputDate() << endl;
    cout << main.InputPhone() << endl;
    cout << main.InputCity() << endl;
    cout << main.InputCountry() << endl;
    cout << main.InputNameStudy() << endl;
    cout << main.InputCityName() << endl;
    cout << main.InputCountryStudy() << endl;
    cout << main.InputNumber() << endl;
    cout << endl;

    cout << "Вывод данных о студенте" << endl;
    cout << main.OutputName() << endl;
    cout << main.OutputDate() << endl;
    cout << main.OutputPhone() << endl;
    cout << main.OutputCity() << endl;
    cout << main.OutputCountry() << endl;
    cout << main.OutputNameStudy() << endl;
    cout << main.OutputCityStudy() << endl;
    cout << main.OutputCountryStudy() << endl;
    cout << main.OutputNumber() << endl;

    return 0;
}