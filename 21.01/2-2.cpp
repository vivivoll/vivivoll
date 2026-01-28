#include <iostream>
#include <cmath>
using namespace std;

//Функция для вычисления определенного интеграла функции на отрезке а и b
double integrate(double a, double b, int n, double(*func)(double)){
    //Интегрирование
    double h = (b - a) / n;
    double sum = 0.0;

    for(int i = 0; i < n; i++){
        //Левая точка отрезка
        double x1 = a * i * h;
        //Правая точка отрезка
        double x2 = a + (i + 1) * h;
        //Площадь трапеции
        sum += (func(x1) + func(x2) * h / 2.0);
    }

    return sum;
}

int main(){
    setlocale(LC_ALL, "ru");
    
    //Указатель функции
    double(*function)(double);
    
    //Присваиваем sin
    function = sin;

    //Вызов функции
    double result = integrate(0.0, 3.14, 1000, function);

    //Вывод результата
    cout << "Результат: " << result << endl;

    return 0;
}