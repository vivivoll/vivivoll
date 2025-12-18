#include <iostream>
#include <cmath>

using namespace std;

// Функция для интегрирования
double Integ(double x) {
    return sin(x);
}

//Функция метода симпсона
double SimpsonMetod(double a, double b, double eps) {
    int n = 2;         
    double S1 = 0;     
    
    double S, h, x, x1, x2, x3;
    int N2, k;
    
   
    double prev_S = 0;

    bool first_iteration = true;
    
    //Цикл для уточнения
    while (true) {
        h = (b - a) / n;        
        x = a;                  
        S = 0;                
        N2 = n / 2;            
        
        //Цикл для суммирования значений функции
        for (k = 1; k <= N2; k++) {
            x1 = x;             
            x2 = x1 + h;        
            x3 = x2 + h;        
            
            // Добавление значений функции в сумму
            S = S + Integ(x1) + Integ(x2) + Integ(x3);
            x = x3;          
        }
        
        prev_S = S1;
        S1 = S;                
      
        //Условие проверки точности
        if (!first_iteration && fabs(S - prev_S) <= eps) {
            break;              
        }
        
        first_iteration = false;
        n = 2 * n;          
    }
    
    // Вывод результата
    cout << "n = " << n << endl;
    cout << "S = " << S << endl;
    return S;
}

int main() {
    //Переменные
    double a, b, eps;
    
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите ε: ";
    cin >> eps;
    
    //Запуск функции
    double result = SimpsonMetod(a, b, eps);
    
    return 0;
}