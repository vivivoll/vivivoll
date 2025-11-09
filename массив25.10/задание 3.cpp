#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	const int row1 = 5;
	const int col1 = 10;
	int array1[row1][col1];

	cout << "Массив 5/10" << "\n";
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col1; j++) {
			array1[i][j] = rand() % 50;
			cout << array1[i][j] << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "\n";
	

	const int row2 = 5;
	const int col2 = 5;
	int array2[row2][col2];

	cout << "Массив 5/5" << "\n";
	for (int i = 0; i < row2; i++) {
		for (int j = 0; j < col2; j++) {
			array2[i][j] = array1[i][j] + array1[i][j+ 1];
			cout << array2[i][j] << "  ";
		}
		cout << "\n";
	}
	return 0;
}