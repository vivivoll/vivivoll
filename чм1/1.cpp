#include <iostream>
#include <cmath>

using namespace std;

//Функция
double f(double x, double y) {
    return x + y;
}

//Метод Эйлера
void eulerMethod() {
    double x0, y0, h;
    int n;
    
    //Ввод начальных данных
    cout << "\nМетод Эйлера\n";
    cout << "x0: ";
    cin >> x0;
    
    cout << "y0: ";
    cin >> y0;
    
    cout << "n: ";
    cin >> n;
    
    cout << "h: ";
    cin >> h;
    
    cout << "\nРезультаты\n";
    cout << "Шаг 0: x = " << x0 << ", y = " << y0 << endl;
    
    // Основной цикл
    for (int i = 1; i <= n; i++) {
        //Вычисление нового значения y
        double y = y0 + h * f(x0, y0);
        double x = x0 + h;
        
        //Вывод результатов для текущего шага
        cout << "Шаг " << i << ": x = " << x << ", y = " << y << endl;
        
        //Обновление значений для следующего шага
        x0 = x;
        y0 = y;
    }
}

//Метод Эйлера Коши
void eulerModifiedMethod() {
    double x0, y0, h;
    int n;
    
    //Ввод начальных данных
    cout << "\nМетод Эйлера Коши\n";
    cout << "x0: ";
    cin >> x0;
    
    cout << "y0: ";
    cin >> y0;
    
    cout << "n: ";
    cin >> n;
    
    cout << "h: ";
    cin >> h;
    
    cout << "\nРезультаты\n";
    cout << "Шаг 0: x = " << x0 << ", y = " << y0 << endl;
    
    // Основной цикл
    for (int i = 1; i <= n; i++) {
        //Прогноз
        double y1 = y0 + h * f(x0, y0);
        double x = x0 + h;
        
        //Пересчет
        double y = y0 + (h / 2.0) * (f(x0, y0) + f(x, y1));
        
        //Вывод 
        cout << "Шаг " << i << ": x = " << x << ", y = " << y << endl;
        
        //Обновление значений для следующего шага
        x0 = x;
        y0 = y;
    }
}

//Метод Рунге-Кутты 4 порядка
void rungeKuttaMethod() {
    double x0, y0, h;
    int n;
    
    //Ввод начальных данных
    cout << "\nМетод Рунге-Кутты 4 порядка\n";
    cout << "x0: ";
    cin >> x0;
    
    cout << "y0: ";
    cin >> y0;
    
    cout << "n: ";
    cin >> n;
    
    cout << "h: ";
    cin >> h;
    
    cout << "\nРезультаты\n";
    cout << "Шаг 0: x = " << x0 << ", y = " << y0 << endl;
    
    // Основной цикл
    for (int i = 1; i <= n; i++) {
        //Вычисление коэффициентов
        double k1 = h * f(x0, y0);
        double k2 = h * f(x0 + h/2, y0 + k1/2);
        double k3 = h * f(x0 + h/2, y0 + k2/2);
        double k4 = h * f(x0 + h, y0 + k3);
        
        //Вычисление нового значения y
        double y = y0 + (1.0/6.0) * (k1 + 2*k2 + 2*k3 + k4);
        double x = x0 + h;
        
        //Вывод результатов 
        cout << "Шаг " << i << ": x = " << x << ", y = " << y << endl;
        
        //Обновление значений для следующего шага
        x0 = x;
        y0 = y;
    }
}

//Функция для меню
void displayMenu() {
    cout << "МЕНЮ: Методы решения\n";
    cout << "1. Метод Эйлера (простой)\n";
    cout << "2. Метод Эйлера с пересчетом\n";
    cout << "3. Метод Рунге-Кутты 4-го порядка\n";
    cout << "4. Выход\n";
    cout << "Ответ: ";
}

int main() {
    int choice = 0;
    
    //Цикл: пока не выбрано 4, показываем меню
    while (choice != 4) {
        displayMenu();
        cin >> choice;
        
        if (choice == 1) {
            eulerMethod();
        }
        else if (choice == 2) {
            eulerModifiedMethod();
        }
        else if (choice == 3) {
            rungeKuttaMethod();
        }
        else if (choice == 4) {
            cout << "\nВыход\n";
        }
        else {
            cout << "\nОшибка\n";
        }
    }
    return 0;
}

/*
ОТВЕТ НА УРАВНЕНИЕ, КОТОРОЕ ВЫДАСТ ПРОГРАММА
Шаг 0: x = 0, y = 1
Шаг 1: x = 0.1, y = 1.1
Шаг 2: x = 0.2, y = 1.22
Шаг 3: x = 0.3, y = 1.362
*/