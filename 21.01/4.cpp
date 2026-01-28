#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    //Переменные
    int a = 5;
    double b = 3.14;

    //delctype 
    decltype(a * b) c_1 = a * b;

    //auto
    auto c_2 = a * b;

    //Вывод результата
    cout << "int: " << a << endl;
    cout << "double: " << b << endl;
    cout << "delctype: " << c_1 << endl;
    cout << "auto: " << c_2 << endl;

    //Главная разница в том, что тип данных auto и decltype определяют автоматически

    return 0;
}