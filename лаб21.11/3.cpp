#include <iostream>
using namespace std;

double number(double value, int n){
    double k = 1;
    for (int i = 0; i < n; i++)
        k *= 10;
    double result = (value * k + 0.5) / k;
    return result;
}

int main(){
    double x = 3.1415926;
    cout << number(x, 2) << endl; 
    cout << number(x, 4) << endl;  
    cout << number(5.6789, 1) << endl; 

    return 0;
}