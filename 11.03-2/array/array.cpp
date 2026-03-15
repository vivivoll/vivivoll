#include <iostream>
#include "array.h"
using namespace std;


//Конструктор по умолчанию
Array::Array(){
    data = nullptr;
    size = 0;
}

//Конструктор с параметрами
Array::Array(int n, int s = 0){
    if(n <= 0){
        data = nullptr;
        size = 0;
        return;
    }
    data = new int[n];
    for(int i  = 0; i < n; i++){
        data[i] = s;
    }
}

//Конструктор копирования
Array::Array(const Array& other){
    data = nullptr;
    size = other.size;
    if(size > 0){
        data = new int[size];
        for(int i = 0; i < size; i++){
            data[i] = other.data[i];
        }
    }
}

//Дестркутор
Array::~Array(){
    delete[] data;
}

//Оператор[]
int& Array::operator[](int index){
    if(index < 0 || index >= size){
        cout << "Вне диапазона!" << endl;
    }
    return data[index];
}

//Оператор ()
void Array::operator()(int value){
    for(int i = 0; i < size; i++){
        data[i] += value;
    }
}

//Методы
//Вывод массива
void Array::Print() const{
    for(int i = 0; i < size; i++){
        cout << data[i];
    }
}

