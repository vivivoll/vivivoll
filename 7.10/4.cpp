#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int a;

	cout << "Значение a: ";
	cin >> a;



	int i = 1;


	while (a <= 20) {
		i *= a;
		a++;
	}

	cout << "Произведение всех чисел: " << i;

	return 0;
}