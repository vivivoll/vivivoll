#include <iostream>
#include <string>
#include <stdexcept>
#include "array.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    //Создание массива
    IntArray arr();

    try{
        arr().at(5);
    }
    catch(const out_of_range& e){
        cout << "Out Of Range: " << e.what() << endl;
    }

    return 0;
}