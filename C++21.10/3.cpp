#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");

	const int january = 31;
	int day[january] = { -23, -25, -35, -32, -31,
						 -34, -31, -40, -36, -37,
						 -38, -25, -26, -27, -28,
						 -29, -35, -40, -31, -40,
						 -35, -31, -31, -40, -31,
						 -38, -38, -38, -38, -38, -35 };

	int sum = 0;
	for (int i = 0; i < january; i++) {
		sum += day[i];
	}
	int average = sum / 31;
	cout << "Средняя температура за январь: " << average << endl;

	int count = 0;
	for (int i = 0; i < january; i++) {
		if (day[i] < -30) {
			count++;
		}
	}
	cout << "Температура падала < -30 градусов: " << count;

						 
	return 0;
}