#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

//Методы

//Вывод работника
void Worker::ShowWorker() const{
	cout << "ФИО: " << FIO << endl;
	cout << "Должность: " << Profession << endl;
	cout << "Год начала работы: " << YearToWork << endl;
	cout << "Зарплата: " << Money << endl;
}

//Поиск работника, которые работают больше заданного года
void Worker::WorkerFromYear(const Worker workers[], int size, int YearToWork) const{
	for (int i = 0; i < size; i++) {
		if (workers[i].GetYearToWork() < 2017) {
			workers[i].ShowWorker();
		}
	}
}

//Поиск работника по зарплате
void Worker::WorkerFromMoney(const Worker workers[], int size, int Money) const{
	for(int i = 0; i < size; i++) {
		if (workers[i].GetMoney() > Money){
			workers[i].ShowWorker();
		}
	}
}

//Поиск работника по профессии
void Worker::WorkerFromProfession(const Worker workers[], int size, const string& Profession) const{
	for(int i = 0; i < size; i++){
		if(workers[i].GetProfession() == Profession){
			workers[i].ShowWorker();
		}
	}
}