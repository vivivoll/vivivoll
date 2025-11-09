#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int sum;
	int all_worker = 0;
	
	
	for (int i = 1; i <= 12; i++) {
		int mesaq = 0;
		int totalsum;

		for (int j = 1; j <= 3; j++) {
			cout << "Зарплата сотрудника: ";
			cin >> sum;
			mesaq += sum;
		}

		cout << "Сотрудник " << i << " за квартал = " << mesaq << endl;
		all_worker += mesaq;
	}
	cout << "Общая выплата по всем сотрудникам: " << all_worker << endl;
	return 0;
}