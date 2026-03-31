#include <iostream>
#include <string>
#include "processor.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    //Объект с параметрами
    Computer pc_1("Gaming", "intel i5", 4, 8);

    //Вывод ПК
    pc_1.printPC();

    
    return 0;
}