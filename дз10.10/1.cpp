#include <iostream>
using namespace std;

int main(){
    setlocale (LC_ALL, "ru");

    int number;
    cout << "Введите число: ";
    cin >> number;

    
    for (; number > 0; number /= 10) {
        int digit = number % 10;  
        cout << digit;            
    }

    cout << endl;






    return 0;
}


