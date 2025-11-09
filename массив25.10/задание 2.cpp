#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	const int row = 3;
	const int col = 4;
	int array[row][col];

	for (int i = 0; i < row; i++) {
		int sum_row = 0;
		for (int j = 0; j < col; j++) {
			array[i][j] = rand() % 10;
			cout << array[i][j] << "  ";
			sum_row += array[i][j];
		}
		cout << "| " << sum_row;
		cout << "\n";
	}
	for (int j = 0; j < col; j++) {
		int sum_col = 0;                   
		for (int i = 0; i < row; i++) {
			sum_col += array[i][j];        
		}
		cout << sum_col << " ";
	}

	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) { 
			sum += array[i][j];
		}
	}
	cout << "| " << sum;
	return 0;
}