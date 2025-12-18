#include <iostream>
#include <algorithm> //Подключение библиотеки для reverse
#include <cstring> //Подключение библиотеки для reverse
using namespace std;


// Функция для подсчёта символов c ссылками
void Count(const string &stroka, int &letters, int &digits, int &spaces, int &others) {
    letters = 0;
    digits = 0;
    spaces = 0;    //Счетчики символов
    others = 0;

    //Длина строки
    int n = stroka.length(); 

    //Цикл для вычисления количества символов
    for (int i = 0; i < n; i++) {
        //Берем первый символ в с
        char c = stroka[i];

        //Проверка на буквы
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            letters++;
        }
        //Проверка на цифры
        else if (c >= '0' && c <= '9') {
            digits++;
        }
        //Проверка на пробелы
        else if (c == ' ') {
            spaces++;
        }
        //Проверка на другие символы
        else {
            others++;
        }
    }
}

int main(){

    //Переменные
    string stroka;
    int letters;
    int digits;
    int spaces;
    int others;

    //Ввод строки
    cout << "String: ";
    //Определяет длину строки
    getline(cin, stroka);

    Count(stroka, letters, digits, spaces, others);

    cout << "Result" << endl;
    cout << "Letters: " << letters << endl;
    cout << "Digits: " << digits << endl;
    cout << "Spaces: " << spaces << endl;
    cout << "Others: " << others << endl; 

    return 0;
}