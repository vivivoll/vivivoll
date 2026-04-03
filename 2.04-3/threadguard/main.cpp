#include <iostream>
#include <string>
#include "ThreadGuard.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    //Создание объекта с передачей функции
    ThreadGuard t1(work1);
    ThreadGuard t2(work2);

    return 0;
}