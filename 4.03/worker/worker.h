#pragma once
#include <iostream>
#include <string>
using namespace std;

//Класс Работник
class Worker {
private:
	string FIO;
	string Profession;
	int YearToWork;
	int Money;

public:
	//Конструктор explicit
	explicit Worker(const string& WorkFIO = "", const string& WorkProfession = "", const int& WorkYearToWork = 0, const int& WorkMoney = 0)
		: FIO(WorkFIO), Profession(WorkProfession), YearToWork(WorkYearToWork), Money(WorkMoney){}

	//Сеттеры для возврата значений
	string GetFIO() const { return FIO; }
	string GetProfession() const { return Profession; }
	int GetYearToWork() const { return YearToWork; }
	int GetMoney() const { return Money; }

	//Методы

	//Вывод работника
	void ShowWorker() const;

	//Поиск работника по годам
	void WorkerFromYear(const Worker workers[], int size, int YearToWork) const;

	//Поиск работника по зарплате
	void WorkerFromMoney(const Worker workers[], int size, int Money) const;
	
	//Поиск работника по профессии
	void WorkerFromProfession(const Worker workers[], int size, const string& Profession) const;
};