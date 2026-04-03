#pragma once
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class AtomicCounter{
private:
    int value;
    mutex m;

public:
    //Конструктор
    AtomicCounter(int v = 0) : value(v) {}

    //Прибавление
    void increment() {
        //Закрытие значения, выполнение, открытие значения 
        lock_guard<mutex> lock(m);
        value++;
    }

    //Уменьшение
    void decrement() {
        //Закрытие значения, выполнение, открытие значения 
        lock_guard<mutex> lock(m);
        value--;
    }

    //Получение
    int get() {
        //Закрытие значения, выполнение, открытие значения 
        lock_guard<mutex> lock(m);
        return value;
    }

};