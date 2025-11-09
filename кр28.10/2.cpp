#include <iostream>
using namespace std;

int main(){
    setlocale (LC_ALL, "ru");
    
    int a,b;

    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    cout << endl;
    cout << "Произведение чисел " << a << " * " << b << " = " << a * b;

    return 0;
}

