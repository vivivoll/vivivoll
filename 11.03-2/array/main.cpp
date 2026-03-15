#include <iostream>
#include "array.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    Array arr_1(3,7);

    //Вывод массива
    arr_1.Print();

    //Вывод второго элемента
    cout << arr_1[2];

    //Изменение элемента
    arr_1[2] = 22;

    //Добавление элемента
    arr_1(8);

    //Вывод результата
    arr_1.Print();
    

    return 0;
}