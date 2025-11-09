#include <iostream>
using namespace std;

int main(){
    setlocale (LC_ALL, "ru");
    
    float a = 3.7;
    float b = 4.5;
    double x = 5;

    cout << "Средне арифметическое: " "("<< a << " + " << b << " + " << x << ")" << " / 3 = " << (a + b + x) / 3 << endl; 
    return 0;
}

