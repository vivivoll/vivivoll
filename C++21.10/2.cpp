#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");

	const int podyest = 10;
	int arr1[podyest] = { 2,3,4,1,4,2,3,2,3,5 };
	int arr2[podyest] = { 2,1,2,2,1,2,1,2,1,2 };
	int arr3[podyest] = { 2,4,2,2,4,2,5,2,4,2 };
	int arr4[podyest] = { 5,1,2,2,4,2,2,1,2,4 };


	int number, pod;
	cout << "Выберите подъезд (от 1 до 4): "; 
	cin >> pod;
	cout << "Выберите номер квартиры (от 1 до 10): "; 
	cin >> number;

	switch (pod) {
	case 1:
		if (number > 0 && number < 11) {
			cout << "Кол-во жильцов: " << arr1[number - 1] << "\n";
			if (number % 2 == 0) {
				cout << "Соседи: " << arr1[number - 2] << '\n';
			}
			else {
				cout << "Соседи: " << arr1[number];
			}
		}
		break;
	
	case 2:
		if (number > 0 && number < 11) {
			cout << "Кол-во жильцов: " << arr2[number - 1] << "\n";
			if (number % 2 == 0) {
				cout << "Соседи: " << arr2[number - 2] << '\n';
			}
			else {
				cout << "Соседи: " << arr2[number];
			}
		}
		break;

	case 3:
		if (number > 0 && number < 11) {
			cout << "Кол-во жильцов: " << arr3[number - 1] << "\n";
			if (number % 2 == 0) {
				cout << "Соседи: " << arr3[number - 2] << '\n';
			}
			else {
				cout << "Соседи: " << arr3[number];
			}
		}
		break;

	case 4:
		if (number > 0 && number < 11) {
			cout << "Кол-во жильцов: " << arr4[number - 1] << "\n" << endl;
			if (number % 2 == 0) {
				cout << "Соседи: " << arr4[number - 2] << '\n' << endl;
			}
			else {
				cout << "Соседи: " << arr4[number] << endl;
			}
		}
		break;
	}

	int sum1 = 0;
	for (int i = 0; i < podyest; i++) {
		sum1 += arr1[i];
	}

	int sum2 = 0;
	for (int i = 0; i < podyest; i++) {
		sum2 += arr2[i];
	}

	int sum3 = 0;
	for (int i = 0; i < podyest; i++) {
		sum3 += arr3[i];
	}

	int sum4 = 0;
	for (int i = 0; i < podyest; i++) {
		sum4 += arr4[i];
	}


	cout << endl;
	cout << "Суммарное кол-во жильцов каждого подъезда: " << endl;
	cout << "1 подъезд: " << sum1 << endl;
	cout << "2 подъезд: " << sum2 << endl;
	cout << "3 подъезд: " << sum3 << endl;
	cout << "4 подъезд: " << sum4 << endl;
	cout << endl;


	cout << "Многодетные семьи (больше 5 человек)" << endl;

	cout << "1 подъезд: ";
	for (int i = 0; i < podyest; i++) {
		if (arr1[i] > 4) {
			cout << i + 1 << "кв" << " ";
		}
	}

	cout << "2 подъезд: ";
	for (int i = 0; i < podyest; i++) {
		if (arr2[i] > 4) {
			cout << 10 + i + 1 << "кв" << " ";
		}
	}

	cout << "3 подъезд: ";
	for (int i = 0; i < podyest; i++) {
		if (arr3[i] > 4) {
			cout << 20 + i + 1 << "кв" << " ";
		}
	}

	cout << "4 подъезд: ";
	for (int i = 0; i < podyest; i++) {
		if (arr4[i] > 4) {
			cout << 30 + i + 1 << "кв" << " ";
		}
	}








	return 0;
}
