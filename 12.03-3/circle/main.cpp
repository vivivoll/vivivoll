#include <iostream>
#include "circle.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    //Объекты
    Circle a(1.0);
    Circle b(2.0);
    
    //Вывод радиуса
    a.Print();
    b.Print();

    //Сравнение радиусов
    if(a == b){
        cout << "Окружности равны" << endl;
    }
    else{
        cout << "Окружности не равны" << endl;
    }

    //Сравнение наибольшей окружности
    if(a > b){
        cout << "а больше b" << endl;
    }
    else{
        cout << "b больше a" << endl;
    }

    //Сложение и вычитание
    a += 5.0;
    b -= 1.0;

    a.Print();
    b.Print();

    return 0;
}