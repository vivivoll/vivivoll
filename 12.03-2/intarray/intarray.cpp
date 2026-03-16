#include <iostream>
#include "initarray.h"
using namespace std;

//Конструктор по умолчанию
IntArray::IntArray(){
    data = nullptr;
    size = 0;
}

//Конструктор от size_t
IntArray::IntArray(size_t n){
    size = n;
    data = new int[size];

    for(int i = 0; i < size; i++){
        data[i] = 0;
    }
}

//Конструктор копирования
IntArray::IntArray(const IntArray& other){
    size = other.size;
    data = new int[size];

    for(size_t i = 0; i < size; i++){
        data[i] = other.data[i];
    }
}

//Конструктор перемещения
IntArray::IntArray(IntArray&& other){
    data = other.data;
    size = other.size;

    other.data = nullptr;
    other.size = 0;
}

//Деструктор
IntArray::~IntArray(){
    delete[] data;
}

//Оператор присваивания копированием
IntArray& IntArray::operator=(const IntArray& other){
    if(this == &other){
        return *this;
    }

    delete[] data;

    size = other.size;
    data = new int[size];

    for(size_t i = 0; i < size; i++){
        data[i] = other.data[i];
    }

    return *this;
}

//Оператор присваивания перемещением
IntArray& IntArray::operator=(IntArray&& other){
    if(this == &other){
        return *this;
    }

    delete[] data;

    size = other.size;
    data = other.data;

    other.size = 0;
    other.data = nullptr;

    return *this;
}
    
//Метод print
void IntArray::print() const{
    for(int i = 0; i < size; i++){
        cout << data[i];
    }
    cout << endl;
}
