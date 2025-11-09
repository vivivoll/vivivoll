#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int first = 1;
	int sum = 0;

	while (first <= 1000) {
		sum += first;
		first++;
	}

	cout << "Сумма всех чисел: " << sum << "\n";
	cout << "Среднее арифмитическое: " << sum / 1000;

	return 0;
}