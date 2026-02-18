#include <iostream>
#include <string>
#include "human.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	//Создание объекта
	Human human_1;

	human_1.inputHuman();
	human_1.outputHuman();
	human_1.getCount();

	return 0;
}