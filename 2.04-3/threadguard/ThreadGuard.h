#pragma once
#include <iostream>
#include <thread>
using namespace std;

class ThreadGuard{
private:
    thread t;

public:
    template<typename Func>
    //Конструктор
    ThreadGuard(Func f) : t(f) {}

    //Запрет копирования
    ThreadGuard(const ThreadGuard&) = delete;
    ThreadGuard& operator=(const ThreadGuard&) = delete;

    //Деструктор
    ~ThreadGuard(){
        if(t.joinable()){
            t.join();
        }
    }
};

//Функция для моментального вывода
void work1() {
    cout << "1 тест" << endl;
}

//Функция для вывода через 2 секунды
void work2() {
    this_thread::sleep_for(chrono::seconds(2));
    cout << "2 тест" << endl;
}