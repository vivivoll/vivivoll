#include <iostream>
#include "salary.h"
#include <string>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    Employee* employees[3];
    //Создание объектов
    employees[0] = new Manager("Алексей", 5000);
    employees[1] = new Engineer("Богдан", 30, 160);
    employees[2] = new SalesPerson("Олег", 2000, 50000, 0.05);

    double total = 0;

    //Вывод
    for (int i = 0; i < 3; i++) {
        employees[i]->displayInfo();
        double salary = employees[i]->calculateSalary();

        cout << "Salary: $ " << salary << "\n\n";

        total += salary;
    }
    cout << "Total payroll: $" << total << "\n";

    //Очистка памяти
    for (int i = 0; i < 3; i++) {
        delete employees[i];
    }

    return 0;
}