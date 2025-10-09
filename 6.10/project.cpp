#include <iostream>

int main() {
	using namespace std;
	setlocale(LC_ALL, "ru");

	char symbol;
	
	cout << "Введите символ: ";
	cin >> symbol;

	switch (symbol) {

		case '.': case ',': case '!':
		case '?': case ':': case ';':

			cout << "Знак препинания";
			break;

		case '1': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9': case '0':

			cout << "Цифра";
			break;

		default:

			if (symbol >= 'A' && symbol <= 'Z') {
				cout << "Буква";
			}
			else if (symbol >= 'a' && symbol <= 'z') {
				cout << "Буква";
			}
			else {
				cout << "Другое";
			}
	}
	return 0;
}