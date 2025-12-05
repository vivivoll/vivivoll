#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    const int size = 5;               //Длина массива
    int array[size] = {3,6,4,7,5};    //Создание массива
    int *ptr = array;                 //Присванивание адреса переменной
    int sum = 0;                      //Переменная для суммы

    for(int i = 0; i < size; i++){
        cout << *(ptr + i) << " ";    //Цикл: вывод массива и сложение каждого элемента в массиве
        sum += *(ptr + i);
    }

    cout << "\nSum: " << sum;         //Вывод результата

    return 0;
}