#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    
    int number;
    int factorial = 1;  
    int i = 1;
    
    cout << "Введите число: ";
    cin >> number;

    while (i <= number) {
        factorial *= i;  
        i++;            
    }

    cout << "Факториал числа: " << number << " = " << factorial;
    return 0;
}
