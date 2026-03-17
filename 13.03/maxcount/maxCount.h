#pragma once
#include <iostream>
#include <cmath>
using namespace std;

template<typename T>

void maxCount(T a, T b){
    if(a > b){
        cout << a << endl;
    }
    else if(b > a){
        cout << b << endl;
    }
    else{
        cout << "=" << endl;
    }
}