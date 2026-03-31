#include <iostream>
#include "house.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    //Создание дома
    House myhouse("Ленина 15");

    //Добавление комнат в дом
    myhouse.addRoom("Гостиная", 28);
    myhouse.addRoom("Спальня", 16);
    myhouse.addRoom("Кухня", 12);

    //Вывод дома с комнатами
    myhouse.print();

    return 0;
}