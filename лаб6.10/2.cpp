#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");


    int first_manager, second_manager, third_manager;
    int total_first_manager, total_second_manager, total_third_manager;

    cout << "Введите уровень продаж менеджера 1: ";
    cin >> first_manager;

    cout << "Введите уровень продаж менеджера 2: ";
    cin >> second_manager;

    cout << "Введите уровень продаж менеджера 3: ";
    cin >> third_manager;

    int money_manager = 200;

   
    if (first_manager <= 500)
        total_first_manager = money_manager + first_manager * 3 / 100;
    else if (first_manager <= 1000)
        total_first_manager = money_manager + first_manager * 5 / 100;
    else
        total_first_manager = money_manager + first_manager * 8 / 100;

   
    if (second_manager <= 500)
        total_second_manager = money_manager + second_manager * 3 / 100;
    else if (second_manager <= 1000)
        total_second_manager = money_manager + second_manager * 5 / 100;
    else
        total_second_manager = money_manager + second_manager * 8 / 100;

    if (third_manager <= 500)
        total_third_manager = money_manager + third_manager * 3 / 100;
    else if (third_manager <= 1000)
        total_third_manager = money_manager + third_manager * 5 / 100;
    else
        total_third_manager = money_manager + third_manager * 8 / 100;

    
    string best_manager_name;
    int best_manager_total;

    if (total_first_manager > total_second_manager && total_first_manager > total_third_manager) {
        best_manager_name = "Менеджер 1";
        total_first_manager += 200;
        best_manager_total = total_first_manager;
    }
    else if (total_second_manager > total_first_manager && total_second_manager > total_third_manager) {
        best_manager_name = "Менеджер 2";
        total_second_manager += 200;
        best_manager_total = total_second_manager;
    }
    else {
        best_manager_name = "Менеджер 3";
        total_third_manager += 200;
        best_manager_total = total_third_manager;
    }


    cout << "Менеджер 1: " << total_first_manager << "\n";
    cout << "Менеджер 2: " << total_second_manager << "\n";
    cout << "Менеджер 3: " << total_third_manager << "\n";


    cout << "Лучший менеджер: " << best_manager_name << ", итоговая сумма с премией: " << best_manager_total << "\n";

    return 0;
}