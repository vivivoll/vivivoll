#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");

	const int massiv = 10;
	int number[massiv] = { 1,1,2,3,4,5,5,6,7,8 };

	for (int i = 0; i < massiv; i++) {
		for (int j = i + 1; j < massiv; j++) {
			if (number[i] == number[j]) {
				cout << number[i];
			}
		}
	}
	return 0;
}

