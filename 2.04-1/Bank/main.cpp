#include <iostream>
#include <string>
#include <stdexcept>
#include "bank.h"
using namespace std;

/*
Обработка исключительных ситуаций:
try - отслеживание исключений
throw - генерация исключений
catch - блок обработки исключения конкретного типа

Полезные бидлиотеки:
exception -> (два наследника)
1. runtime_error
2. logic_error
*/

/*
namespace - это механизм, позволяющий группировать имена и избегать конфликтов имен
std:: - стандартная пространство
Вложенное пространство namespace A::B{}
Анонимное пространство имен
*/

int main(){
    setlocale(LC_ALL, "ru");

    try{
        BankAccount acc_1(-100); //Вызов invalid_argument
    }
    catch(const invalid_argument& e){
        cout << "Invalid Argument: " << e.what() << endl;
    }

    BankAccount acc_2(500);
    try{
        acc_2.withdraw(600); //Вызов runtime_error
    }
    catch(const runtime_error& e){
        cout << "Runtime Error: " << e.what() << endl;
    }

    return 0;
}