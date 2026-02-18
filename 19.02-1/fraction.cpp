#include <iostream>
#include "fraction.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");

	Fraction fraction1;

	cout << "Ввод данных дроби" << endl;
	fraction_1.InputNumerator();
	fraction_1.InputDenominator();

	cout << "Математические операции" << endl;
	fraction_1.Plus();
	fraction_1.Minus();
	fraction_1.Multiplication();
	fraction_1.Division();


	return 0;
}