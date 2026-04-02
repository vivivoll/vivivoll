#include <iostream>
#include <string>
#include <stdexcept>
#include "bank.h"
using namespace std;

//Конструктор
BankAccount::BankAccount(int b) : balance(b) {
    if(balance < 0){
        throw invalid_argument("Баланс отрицательный");
    }
}

//Метод снятия денег
void BankAccount::withdraw(int amount){
    //runtime_error
    if(amount > balance){
        throw runtime_error("Нельзя снять сумму больше баланса");
    }

    //invalid_argument
    if(amount < 0){
        throw invalid_argument("Нельзя снять отрицательную сумму");
    }
}


