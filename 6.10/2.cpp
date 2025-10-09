#include <iostream>
using namespace std;


int main() {
	setlocale(LC_ALL, "ru");

	int input, output, minute;

	cout << "С какого оператора будет проходить звонок?\n1.МТС,\n2.Мегафон\n";
	cin >> input;

	cout << "На какой оператор будет проходить звонок?\n1.МТС,\n2.Мегафон\n";
	cin >> output;

	cout << "Сколько минут будет длиться звонок?\n";
	cin >> minute;


	switch (input) {
	case 1:
		switch (output) {
		case 1:
			cout << "Звонок будет бесплатным";
			break;
		case 2:
			cout << "Звонок составит: " << minute * 1.5 << " рублей";
			break;
		}
		break;
	case 2:
		switch (output) {
		case 1:
			cout << "Звонок составит: " << minute * 2 << " рублей";
			break;
		case 2:
			cout << "Звонок будет бесплатным";
			break;
		}
		break;
	}


	return 0;
}




