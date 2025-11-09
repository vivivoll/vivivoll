#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int number;
    cout << "Введите число: ";
    cin >> number;

    int sum = 0; 

    for (; number > 0; number /= 10) {
        int digit = number % 10;
        sum += digit;
    }

    cout << sum << "\n";

    return 0;
}
