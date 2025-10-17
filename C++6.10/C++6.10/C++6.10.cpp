/*#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int one, two, three, four, five;

	cout << "Введите 1 оценку студента:";
	cin >> one;
	cout << "Введите 2 оценку студента:";
	cin >> two;
	cout << "Введите 3 оценку студента:";
	cin >> three;
	cout << "Введите 4 оценку студента:";
	cin >> four;
	cout << "Введите 5 оценку студента:";
	cin >> five;

	int summa=one+two+three+four+five;
	if ((summa / 5) >= 4) {
		cout << "Допуск";
	}
	else {
		cout << "Не допуск";
	}

	return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int number, total_1, total_2;

	cout << "Введите число:";
	cin >> number;



	if (number % 2 == 0) {
		total_1 = number * 3;
		cout << "Число четное\nРезультат:" << total_1;
	}
	else if (number % 2 == 1) {
		total_2 = number / 2;
		cout << "Число нечетное\nРезультат:" << total_2;
	}

	return 0;
}
*/
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int first, second, function;

	cout << "Первое число:";
	cin >> first;
	cout << "Второе число:";
	cin >> second;
	cout << "Выбор действия:\n1 => +\n2 => -\n3 => /\n4 => *\nОтвет:";
	cin >> function;

	switch (function) {
	case 1:
		cout << "Результат:" << first + second;
		break;
	case 2:
		cout << "Результат:" << first - second;
		break;
	case 3:
		cout << "Результат:" << first / second;
		break;
	case 4:
		cout << "Результат:" << first * second;
		break;
	}
	return 0;
}
