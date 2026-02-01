#pragma once
#include <string>

//определение приоритета операторов
int priority(char op);

//применение арифметической операции к двум числам
double applyOperation(double a, double b, char op);

//основная функция вычисления выражения
double calculateExpression(const std::string& expression);