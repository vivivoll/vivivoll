#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	const int row = 3;
	const int col = 3;

	int sum = 0;
	int array[row][col];
	int max = array[0][0];
	int min = array[0][0];


	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {
			array[i][j] = rand() % 100;
			cout << array[i][j] << " ";
			sum += array[i][j];
			if (array[i][j] > max) {
				max = array[i][j];
			}
			if (array[i][j] < min) {
				min = array[i][j];
			}
		}
		cout << "\n";
		cout << endl;
		
	}
	
	cout << "Sum: " << sum;
	cout << endl;
	cout << "Average: " << sum / (row * col);
	cout << endl;
	cout << "";
	cout << endl;
	cout << "Max: " << max;
	cout << endl;
	cout << "Min: " << min;
	return 0;
}