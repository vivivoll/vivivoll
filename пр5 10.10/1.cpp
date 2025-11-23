#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int number;
    cout << "Введите число: ";
    cin >> number;

    int n = number;
    int count = 0;        
    int sum = 0;          
    int zeros = 0;       

    for (; n != 0; n /= 10) {
        int digit = n % 10;

        if (digit < 0) digit = -digit; 
        count++;

        sum += digit;

        if (digit == 0)
            zeros++;
    }

    int average;
    if (count > 0){ 
        average = sum / count;
        }
    
        else { 
        average = 0;
    }


    
    cout << "Количество цифр: " << count << endl;
    cout << "Сумма цифр: " << sum << endl;
    cout << "Среднее арифметическое: " << average << endl;
    cout << "Количество нулей: " << zeros << endl;

    return 0;
}
