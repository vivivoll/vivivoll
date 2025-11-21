#include <iostream>
using namespace std;

int Factorial(int a){
    int count = 1;
    for(int i = 1; i <= a; i++){
        count *= i;
    }
    return count;
}

int main(){
    setlocale(LC_ALL, "ru");

    cout << Factorial(3);

    return 0;
}