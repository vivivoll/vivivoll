//1
/*
#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    int a = 10;
    int b = 20;         //Переменные

    cout << a << b << "\n";     //Вывод чисел до результата

    int *ptra = &a;             //Разыменование числа
    int *ptrb = &b;             //Разыменование числа

    int temp = *ptra;           //Третья переменная: берет значение первой переменной
    *ptra = *ptrb;              //Первая переменная = вторая переменная
    *ptrb = temp;               //Вторая переменная = третья переменная

    cout << a << b;             //Вывод результата

    return 0;
}
*/
//2
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int arr[5] = { 1,2,3,4,5 };   //Одномерный массив
    int sum = 0;                //Счетчик

    int* ptr = arr;             //Указатель начала массива
    int* ptr1 = arr + 5;        //Указатель последнего массива

    while (ptr < ptr1) {          //Цикл: пока ptr < ptr1, то сумма + ptr
        sum += *ptr;
        ptr++;
    }

    cout << "Sum: " << sum << endl; //Вывод результата
    return 0;
}