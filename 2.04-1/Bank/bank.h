#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class BankAccount {
private:
    int balance; //Баланс
public:
    //Конструктор
    BankAccount(int b);

    //Метод снятия денег
    void withdraw(int amount);
};
