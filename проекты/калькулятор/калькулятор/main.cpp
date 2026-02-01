#include "калькулятор.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Поддерживаемые операции: (), +, -, *, /" << endl;
    cout << "Введите пример" << endl;

    string expression;

    while (true) {
        cout << "> ";
        getline(cin, expression);

        //пропуск пустых строк
        if (expression.empty()) {
            continue;
        }

        try {
            //вычисление выражения
            double result = calculateExpression(expression);
            cout << "Результат: " << result << endl;
        }
        catch (const exception& e) {
            //обработка ошибок
            cout << e.what() << endl;
            cout << "Пожалуйста, введите выражение снова." << endl;
        }
    }

    cout << "Программа завершена." << endl;
    return 0;
}