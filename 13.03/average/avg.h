#pragma once
#include <iostream>
using namespace std;

template<typename T>
double avg(T arr[], int size){
    //Проверка размера массива
    if(size <= 0){
        return T{};
    }

    T sum = 0;

    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum / size;
}


