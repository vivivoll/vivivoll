#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int x, y;
	int i = 0;
	int result = 1;

	cout << "Первое целое число: "; 
	cin >> x;
	cout << "Второе целое число: "; 
	cin >> y;

	while (i < y) {
		result *= x;
		i++;
		cout << result << "\n";
	}

	return 0;
}