#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int a = 2;
	int b = 1000;

	for (int i = a; i <= b; i++) {
		int count = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				count++;
			}
		}
		if (count == 2) {
			cout << i << "  ";
		}
	}
	return 0;
}