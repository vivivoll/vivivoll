#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int k;
	int i = 1;

	cout << "Значение k: "; //5
	cin >> k;

	while (i <= 10) {
		int result = k * i;
		cout << result << "\n";
		i++;
	}

	return 0;
}