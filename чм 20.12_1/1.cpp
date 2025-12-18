#include <iostream>
#include <cmath>

using namespace std;

// Функция для интегрирования
double Integ(double x) {
    return sin(x);
}

// Функция метода левых прямоугольников
double PramUgol(double a, double b, double eps) {
    double I0 = 0;   
    double I1 = INFINITY; // из cmath.h означает бесконечное значение
    int n = 5;         
    
    double h;
    
    //Цикл: пока разница больше eps 
    while (fabs(I1 - I0) > eps) {
        n = 2 * n;      
        I0 = I1;        
        h = (b - a) / n; 
        I1 = 0;       
        
        //Цикл для вычисления суммы значений функций
        for (int i = 0; i < n; i++) {
            double x = a + i * h; // x = a + i*h
            I1 = I1 + Integ(x);       // I1 = I1 + f(x)
        }
        I1 = I1 * h;    // I1 = I1 * h
    }
    
    //Вывод результата
    cout << "Значение интеграла I1: " << I1 << endl;
    cout << "Число отрезков n: " << n << endl;
    
    return I1;
}

int main() {
    //Переменные
    double a, b, eps;
    //Ввод переменных
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите e: ";
    cin >> eps;
    
    //Применение функции и вывод результата
    double result = PramUgol(a, b, eps);
    
    return 0;
}