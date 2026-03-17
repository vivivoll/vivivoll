#pragma once
#include <iostream>
#include <cmath>
using namespace std;

template<typename T>

void minCount(T a, T b){
    if(a > b){
        cout << b << endl;
    }
    else if(b > a){
        cout << a << endl;
    }
    else{
        cout << "=" << endl;
    }
}