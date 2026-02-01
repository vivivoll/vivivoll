#include "калькулятор.h"
#include <stack>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

//определения приоритета операторов
int priority(char op) {
    if (op == '+' || op == '-') {
        return 1;  //низкий
    }
    else if (op == '*' || op == '/') {
        return 2;  //высокий
    }
    return 0; //для остального
}

//выполнения арифметической операции
double applyOperation(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0) {
            throw runtime_error("Ошибка: деление на ноль");
        }
        return a / b;
    default: throw runtime_error("Неизвестная операция");
    }
}

//основная функция вычисления выражения
double calculateExpression(const string& expression) {
    stack<double> values;    //стек для чисел
    stack<char> operators;   //стек для операторов

    for (size_t i = 0; i < expression.length(); i++) {
        char current = expression[i];

        //пропуск пробелов
        if (current == ' ') {
            continue;
        }

        //считывание числа
        if (isdigit(current)) {
            string numStr;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                numStr += expression[i];
                i++;
            }
            i--;

            double num = stod(numStr); //преобразование строки в число
            values.push(num);
        }
        //открывающая скобка
        else if (current == '(') {
            operators.push(current);
        }
        //закрывающая скобка
        else if (current == ')') {
            //выполнение операций пока не встретится '('
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                if (values.size() < 2) {
                    throw runtime_error("Ошибка: некорректное выражение");
                }

                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();

                values.push(applyOperation(a, b, op));
            }

            //удаление '('
            if (!operators.empty() && operators.top() == '(') {
                operators.pop();
            }
            else {
                throw runtime_error("Ошибка: несбалансированные скобки");
            }
        }
        //арифметические операторы
        else if (current == '+' || current == '-' || current == '*' || current == '/') {
            //выполнение операций с более высоким или равным приоритетом
            while (!operators.empty() &&
                priority(operators.top()) >= priority(current)) {
                char op = operators.top();
                operators.pop();

                if (values.size() < 2) {
                    throw runtime_error("Ошибка: некорректное выражение");
                }

                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();

                values.push(applyOperation(a, b, op));
            }

            //добавление текущего оператора в стек
            operators.push(current);
        }
        //недопустимый символ
        else {
            throw runtime_error("Ошибка: недопустимый символ в выражении");
        }
    }

    //выполнение оставшихся операций
    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();

        if (values.size() < 2) {
            throw runtime_error("Ошибка: некорректное выражение");
        }

        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();

        values.push(applyOperation(a, b, op));
    }

    //последнее значение в стеке это результат
    if (values.empty()) {
        throw runtime_error("Ошибка: выражение не содержит чисел");
    }

    return values.top();
}