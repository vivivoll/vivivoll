#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (i == j || i + j == 6 || i == 3 || j == 3) {
				cout << " * ";
			}
			else {
				cout << "   ";
			}
		}
		cout << endl;
	}	
	return 0;
}