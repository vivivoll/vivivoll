#include "Date.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    //Создание дат
    Date date1(3, 3, 2026);
    Date date2(2, 3, 2026);

    //Вывод
    cout << "Дата 1: ";
    date1.print();
    cout << endl;

    cout << "Дата 2: ";
    date2.print();
    cout << endl;

    //Вычисление разницы между датами
    long diff = date1 - date2;
    cout << "Разность в днях: " << diff << endl;

    //Прибавление 30дней к первой дате
    Date date3 = date1 + 30;
    cout << "Дата 1 + 30 дней: ";
    date3.print();
    cout << endl;

    return 0;
}