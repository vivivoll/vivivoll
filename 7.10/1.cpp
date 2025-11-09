#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int number, sum = 0;
	
	cout << "Введите целое число до 500: ";
	cin >> number;

	while (number <= 500) {
		sum += number;
		number++;
	}

	cout << "Сумма целых чисел: " << sum;

	return 0;
}