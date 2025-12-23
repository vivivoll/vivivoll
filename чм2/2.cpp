#include <iostream>
#include <cmath>

using namespace std;

//Функции для уравнений
double f1(double x, double y, double z) {
    return z;
}

double f2(double x, double y, double z) {
    return -y;
}

int main() {
    //Ввод начальных данных
    double x0, y0, z0, h;
    int n;
    
    cout << "x0: ";
    cin >> x0;
    
    cout << "y0: ";
    cin >> y0;
    
    cout << "z0: ";
    cin >> z0;
    
    cout << "n: ";
    cin >> n;
    
    cout << "h: ";
    cin >> h;
    
    //Начальные значения для вывода
    double initial_x = x0;
    double initial_y = y0;
    double initial_z = z0;
    
    cout << "\nРезультаты" << endl;
    cout << "0\t" << x0 << "\t\t" << y0 << "\t\t" << z0 << endl;
    
    //Основной цикл Рунге-Кутты
    for (int i = 1; i <= n; i++) {
        //Коэф для первого уравнения 
        double k1 = h * f1(x0, y0, z0);
        double k2 = h * f1(x0 + h/2, y0 + k1/2, z0 + k1/2);
        double k3 = h * f1(x0 + h/2, y0 + k2/2, z0 + k2/2);
        double k4 = h * f1(x0 + h, y0 + k3, z0 + k3);
        
        //Коэф для второго уравнения 
        double L1 = h * f2(x0, y0, z0);
        double L2 = h * f2(x0 + h/2, y0 + L1/2, z0 + L1/2);
        double L3 = h * f2(x0 + h/2, y0 + L2/2, z0 + L2/2);
        double L4 = h * f2(x0 + h, y0 + L3, z0 + L3);
        
        //Новые значения y и z
        double y = y0 + (k1 + 2*k2 + 2*k3 + k4) / 6;
        double z = z0 + (L1 + 2*L2 + 2*L3 + L4) / 6;
        double x = x0 + h;
        
        //Вывод результатов
        cout << i << "\t" << x << "\t\t" << y << "\t\t" << z << endl;
        
        //Обновление значений для следующей итерации
        x0 = x;
        y0 = y;
        z0 = z;
    }
    //Вывод результатов
    cout << "x = " << x0 << endl;
    cout << "y = " << y0 << endl;
    cout << "z = " << z0 << endl;
    
    return 0;
}

/*
РЕЗУЛЬТАТ С ВВОДОМ УРАВНЕНИЯ В ПРОГРАММУ
0	2		4.5		3.2
1	2.1		4.83051		3.006
2	2.2		5.13104		2.82604
3	2.3		5.4016		2.65934
4	2.4		5.64221		2.50501
5	2.5		5.85291		2.36223
x = 2.5
y = 5.85291
z = 2.36223
*/