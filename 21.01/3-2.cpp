#include <iostream>
#include <cmath>
using namespace std;

//Функция увеличения значения на 1
int incrememt(int a){
    return a + 1;
}

//Функция возведения числа в квадрат
int square(int a){
    return a * a;
}

//Функция смены знака числа
int negative(int a){
    return -a;
}

int main(){
    setlocale(LC_ALL, "ru");

    //Указатель на функцию
    int(*transformers[3])(int);
    int a;

    cout << "Number: ";
    cin >> a;

    cout << "Result increment: " << incrememt(a) << endl;
    cout << "Result square: " << square(a) << endl;
    cout << "Result negate: " << negative(a) << endl;

    return 0;
} 