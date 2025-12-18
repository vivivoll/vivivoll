#include <iostream>
#include <algorithm> //Подключение библиотеки для reverse
#include <cstring> //Подключение библиотеки для reverse
using namespace std;

//Функция проверки префикса
bool startsWith(const string &stroka, const string &prefix) {
    int n = stroka.length(); //Длина строки
    int m = prefix.length(); //Длина строки

    //Цикл проверки строки и префикса
    for (int i = 0; i < m; i++) {
        //Если найдена неточность (строка != префикс)
        if (stroka[i] != prefix[i]) {
            return false; 
        }
    }
    return true; 
}

//Функция проверки суффикса
bool endsWith(const string &stroka, const string &suffix) {
    int n = stroka.length();
    int m = suffix.length();

    //Цикл сравнения строки и префикса с конца строки
    for (int i = 0; i < m; i++) {
        //Если найдена неточность
        if (stroka[n - m + i] != suffix[i]) {
            return false; 
        }
    }
    return true; 
}

int main() {
    string stroka, prefix, suffix;

    //Ввод строки
    cout << "String: ";
    getline(cin, stroka);
    //Ввод префикса
    cout << "Prefix: ";
    getline(cin, prefix);
    //Ввод суффикса
    cout << "Suffix: ";
    getline(cin, suffix);

    //Вывод проверки префикса
    if (startsWith(stroka, prefix)) {
        cout << "Prefix: YES" << endl;
    } else {
        cout << "Prefix: NO" << endl;
    }

    //Вывод проверки суффикса
    if (endsWith(stroka, suffix)) {
        cout << "Suffix: YES" << endl;
    } else {
        cout << "Suffix: NO" << endl;
    }

    return 0;
}