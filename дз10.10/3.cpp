#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int day;
    int total = 15; 
    int start = 15;

    cout << "Введите дни: ";
    cin >> day;

    for (int i = 2; i <= day; i++) {
        start += 2;
        total += start;
    }

    cout << "Улитка прошла: " << total << " см";
    return 0;
}