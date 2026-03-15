#include <iostream>
#include "operator.h"
using namespace std;

//Конструктор по умолчанию
Mathematics::Mathematics(){
    array = nullptr;
    size = 0;
}

//Конструктор с параметрами
Mathematics::Mathematics(int *arr, int s){
    size = s;
    array = new int[size];

    for(int i = 0; i < size; i++){
        array[i] = arr[i];
    }
}

//Конструктор копирования
Mathematics::Mathematics(const Mathematics& other){
    size = other.size;
    array = new int[size];

    for(int i = 0; i < size; i++){
        array[i] = other.array[i];
    }
}

//Деструктор
Mathematics::~Mathematics(){
    delete[] array;
}


//Методы

//Проверка принадлежности элемента множеству
bool Mathematics::Belonging(int value) const{
    for(int i = 0; i < size; i++){
        if(array[i] == value){
            return true;
        }
    }
    return false;
}

//Добавление элемента в множество (+, +=);
Mathematics Mathematics::operator+(int value) const{

    if(Belonging(value))
        return *this;

    Mathematics result;

    result.size = size + 1;
    result.array = new int[result.size];

    for(int i = 0; i < size; i++)
        result.array[i] = array[i];

    result.array[size] = value;

    return result;
}

//Удаление элемента (-, -=);
Mathematics Mathematics::operator-(int value) const{

    if(!Belonging(value))
        return *this;

    Mathematics result;
    result.size = size - 1;
    result.array = new int[result.size];

    int j = 0;

    for(int i = 0; i < size; i++){
        if(array[i] != value){
            result.array[j++] = array[i];
        }
    }

    return result;
}

//Объединение двух множеств (+, +=);
Mathematics Mathematics::operator+(const Mathematics& other) const{
    Mathematics result;

    result.size = size;
    result.array = new int[size + other.size];

    for(int i = 0; i < size; i++){
        result.array[i] = array[i];
    }

    int newSize = size;

    for(int i = 0; i < other.size; i++){
        if(!Belonging(other.array[i])){
            result.array[newSize++] = other.array[i];
        }
    }
}

//Пересечение множеств (*, *=);
Mathematics Mathematics::operator*(const Mathematics& other) const{
    Mathematics result;

    for(int i = 0; i < size; i++){
        if(other.Belonging(array[i])){
            result = result + array[i];
        }
    }
    return result;
}

//Cравнения множеств (==);
bool Mathematics::operator==(const Mathematics& other) const{
    if(size != other.size){
        return false;
    }

    for(int i = 0; i < size; i++){
        if(!other.Belonging(array[i])){
            return false;
        }
    }
    return true;
}