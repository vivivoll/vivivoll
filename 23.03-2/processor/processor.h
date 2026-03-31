#pragma once
#include <iostream>
using namespace std;

class Processor{
private:
    string name;
    int yadro;
    int potok;

public:
    //С параметрами
    Processor(const string& n, int y, int p);

    //Деструктор
    ~Processor();

    //Метод вывода
    void print() const;
};

//////////////////////////////////

class Computer{
private:
    string namePC;
    Processor* proc; //Композиция
    Computer(const Computer& other) = delete; //Запрет копирования

public:
    //С параметрами
    Computer(const string& comp, const string& pr, int y, int p);

    //Деструктор
    ~Computer();

    //Метод вывода
    void printPC() const;
};
