#include <iostream>
#include "fraction.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Fraction main;

    cout << "Ввод данных дроби\n";
    main.InputNumerator();
    main.InputDenominator();

    cout << "\n";
    main.Print();
    cout << "\n\n";

    cout << "Математические операции:\n";
    main.Plus();
    main.Minus();
    main.Multiplication();
    main.Division();

    return 0;
}