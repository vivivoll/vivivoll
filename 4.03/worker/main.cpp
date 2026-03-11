#include <iostream>
#include <string>
#include <windows.h>
#include "worker.h"
using namespace std;

int main() {
	SetConsoleOutputCP(CP_UTF8);

	//Массив объектов
	Worker workers[3] = {
		Worker("И.А.Иванов", "Уборщик", 2017, 15000),
		Worker("Н.О.Петров", "Консультант", 2020, 30000),
		Worker("Р.Е.Ренатов", "Мененджер", 2010, 50000)
	};

	cout << "Вывод работников" << endl;
	//Которые работают больше заданного года
	workers[3].WorkerFromYear(workers, 3, 2017);
	cout << endl;

	//Которые превосходят заданную зарплату
	workers[3].WorkerFromMoney(workers, 3, 25000);
	cout << endl;

	//Которые имеют заданную должность
	workers[3].WorkerFromProfession(workers, 3, "Консультант");

	return 0;
}