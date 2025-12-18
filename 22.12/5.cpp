#include <iostream>
#include <algorithm> //Подключение библиотеки для reverse
#include <cstring> //Подключение библиотеки для reverse
using namespace std;

//Функция для форматирования ФИО
void NameFio(const string name){
    int n = name.length(); //Находим длину строки
    int space = 0; //Счетчик пробелов

    //Цикл для форматирования
    for(int i = 0; i < n; i++){
        char stroka = name[i];
        //Условие проверки наличия пробелов
        if(stroka == ' '){
            space++;
        }
    }
}

int main() {
    //Переменная
    string name;
    
    cout << "Введите ФИО: ";
    getline(cin, name);


    return 0;
}