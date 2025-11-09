#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	const int row1 = 3;
	const int col1 = 3;
	int array1[row1][col1];
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col1; j++) {
			array1[i][j] = rand() % 50;
			cout << array1[i][j] << " ";
		}
		cout << "\n\n";
	}

	int sdvig;
	cout << "Выберите насколько сдвинуть массив - ";
	cin >> sdvig;


	const int row2 = 3;
	const int col2 = 3;
	int array2[row2][col2];
	for (int i = 0; i < row2; i++) {
		for (int j = 0; j < col2; j++) {
			array2[i][j] = rand() % 50;
			array2[i][j] += sdvig;
			cout << array2[i][j] << " ";
		}
		cout << "\n\n";
	}




	return 0;
}