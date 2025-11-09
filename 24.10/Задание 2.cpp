#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	
	int size;
	cout << "Введите число - ";
	cin >> size; 


	const int row = 3;
	const int col = 3;
	int array[row][col];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << size << " ";
			size += 1;
		}
		cout << "\n\n";
	}


	return 0;
}