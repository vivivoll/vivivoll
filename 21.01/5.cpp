#include <iostream>
using namespace std;

//Шаблон функции
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b){
    return a + b;
} 

int main(){
    setlocale(LC_ALL, "ru");

    //Переменныее
    int a = 2;
    float b = 5.5;

    //Тестовый пример сложения разных типов
    cout << a << " + " << b << " = " << add(a,b);


    return 0;
}