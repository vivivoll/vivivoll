#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int text, back;
	cout << "Выберите цвет фона - ";
	cin >> back;

	cout << "Выберите цвет текста - ";
	cin >> text;

	SetConsoleTextAttribute(hConsole, (back << 4) | text);



	return 0;
}