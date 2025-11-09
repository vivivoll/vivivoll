#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");

	const int size = 10;
	int a[size] = { 1,2,3,4,5,6,7,8,9,10 };
	int b[size] = { 1,2,3,4,5,6,7,8,9,10 };

	int x[20];

	for (int i = 0; i < size; i++) {
		x[i] = a[i];
		x[size + i] = b[i];
	}

	cout << "Следование: ";

	for (int i = 0; i < 20; i++) {
		cout << x[i] << " ";
	}
	cout << endl;



	for (int i = 0; i < size; i++) {
		x[2 * i] = a[i];
		x[2 * i + 1] = b[i];
	}

	cout << "Чередование: ";
	for (int i = 0; i < 20; i++) {
		cout << x[i] << " ";
	}
	return 0;
}

