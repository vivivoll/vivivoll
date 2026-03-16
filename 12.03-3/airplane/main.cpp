#include <iostream>
#include <string>
#include "airplane.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    //Объекты
    Airplane air_1("Boeing 737", 180);     
    Airplane air_2("Boeing 737", 180);

    //Вывод самолетов
    air_1.Print();
    air_2.Print();

    //Сравнение типов
    if(air_1 == air_2){
        cout << "Равны" << endl;
    }
    else{
        cout << "Не равны" << endl;
    }

    //Увеличение кол-ва пассажиров
    ++air_1;
    ++air_2;
    ++air_2;

    air_1.Print();
    air_2.Print();

    //Сравнение вместительности
    if(air_1 > air_2){
        cout << "Первый больше вмещает второго" << endl;
    }
    else{
        cout << "Второй больше вмещает первого" << endl;
    }

    return 0;
}