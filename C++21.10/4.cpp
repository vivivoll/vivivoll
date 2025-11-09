#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");

	const int car = 10;
	int price[car] = { 100000, 200000, 12000000, 400000, 500000, 600000, 700000, 800000, 12000000, 1000000 };
	
	int max = price[0];
	for (int i = 0; i < car; i++) {
		if (price[i] > max) {
			max = price[i];
		}
	}
	cout << "Максимальная цена машины: " << max << endl;

	int first = -1;
	for (int i = 0; i < car; i++) {
		if (price[i] == max) {
			first = i + 1;  
			break;        
		}
	}

	int last = -1;
	for (int i = 0; i < car; i++) {
		if (price[i] == max) {
			last = i + 1;  
		}
	}

	cout << "Первый автомобиль: " << first << endl;
	cout << "Последний автомобиль: " << last << endl;

	return 0;
}