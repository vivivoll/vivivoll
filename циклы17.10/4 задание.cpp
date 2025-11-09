#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int code = 567;
	int count = 0;
	
	for (int i = code; i <= 987; i++) {
		
		int first = i / 100;
		int second = (i / 10) % 10;
		int third = i % 10;
		
		if (first != second && first != third && second != third) {
			cout << i << "\n";
			count++;
		}
	}
	cout << "Кол-во комбинаций = " << count;
	cout << endl;
	cout << "Время на открытие = " << count * 3;

	return 0;
}