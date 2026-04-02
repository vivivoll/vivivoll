#include <iostream>
#include <string>
#include <stdexcept>
#include "array.h"
using namespace std;

//Конструктор
IntArray::IntArray(int c, int* d) : count(c), data(d) {}

//Метод возврата элемента по индексу
int IntArray::at(int index){

    if(index >= count){
        throw out_of_range("Индекс выходит за границу динамического массива");
    }

    int number;
    for(int i = 0; i < index; i++){
        int number = index;
    }
    return number;
}

//Деструктор
IntArray::~IntArray(){
    delete data;
}