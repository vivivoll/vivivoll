#include <iostream>
#include <string>
#include "processor.h"
using namespace std;

//С параметрами
Processor::Processor(const string& n, int y, int p) : name(n), yadro(y), potok(p) {
    cout << "Процессор добавлен" << endl;
}

//Деструктор
Processor::~Processor(){
    cout << "Процессор удален" << endl;
}

void Processor::print() const{
    cout << "Процессор" << endl;
    cout << "Название: " << name << endl;
    cout << "Ядер: " << yadro << endl;
    cout << "Потоков: " << potok << endl;
}

//////////////////////////////

//С параметрами
Computer::Computer(const string& comp, const string& pr, int y, int p) : namePC(comp) {
    proc = new Processor(pr, y, p);
}

//Деструктор
Computer::~Computer(){
    delete proc;
    cout << "Компьютер удален" << endl;
}

//Метод вывода
void Computer::printPC() const{
    cout << "Компьютер" << endl;
    cout << "Название ПК: " << namePC << endl;
    proc->print();
}
