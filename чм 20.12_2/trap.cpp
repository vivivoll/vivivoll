#include <iostream>
#include <cmath>
using namespace std;

// Функция для интегрирования 
double Integ(double x) {
    return sin(x); 
}

//Функция метода трапеций
double trapechiy(double a, double b, int n) {
    double S = 0;           
    double h = (b - a) / n; 
    double x = a + h;       
    
    // Цикл пока x < b
    while (x < b) {
        double F = Integ(x);   
        S = S + F;          
        x = x + h;          
    }
    double Fa = Integ(a);       
    double Fb = Integ(b);       
    
    //Итоговая формула трапеций
    S = (h / 2) * (Fa + Fb + 2 * S); // S := (h/2)*(Fa + Fb + 2*S)
    return S;               
}

int main() {
    //Переменные
    double a, b;
    int n;
    
    //Ввод a, b, n
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите n: ";
    cin >> n;
    
    //Условие проверки на положительное число
    if (n <= 0) {
        cout << "Ошибка: n должно быть положительным!" << endl;
        return 1;
    }
    //Запуск функции метода трапеции
    double result = trapechiy(a, b, n);
    //Вывод результата
    cout << "Приближенное значение интеграла: " << result << endl;
    return 0;
}