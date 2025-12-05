#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    int a, b;       //Переменные двух чисел
    int *pa, *pb;   //Указатели на переменную
    pa = &a;        //Разыменование
    pb = &b;    

    char z;         //Переменная математического знака
    char *pz;       //Указатель на переменную
    pz = &z;        //Разыменование

    cout << "First number: ";
    cin >> a;
    cout << "Second number: ";
    cin >> b;                       //Ввод значений для переменных
    cout << "Sign: ";
    cin >> z;

    int result;

    if(*pz == '+'){
        result = *pa + *pb;
    }
    if(*pz == '-'){
        result = *pa - *pb;
    }                               //Условие для проверки математического знака и подсчета ответа
    if(*pz == '*'){
        result = *pa * *pb;
    }
    if(*pz == '/'){
        result = *pa / *pb;
    }
    else{
        cout << "Ошибка";
    }

    cout << *pa << *pz << *pb << " = " << result;   //Вывод ответа


    return 0;
}