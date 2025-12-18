#include <iostream>
#include <algorithm> //Подключение библиотеки для reverse
#include <cstring> //Подключение библиотеки для reverse
using namespace std;

void Output(const string &stroka){

    //Переменная для подсчета длины строки
    int n = stroka.length();  
    string str = ""; //Строка, в которой будут находиться уникальные символы

    //Цикл для удаления повторных символов
    for(int i = 0; i < n; i++){
        char c = stroka[i];
        //Начальное значение до проверки false
        bool found = false;

        //Перебор строки для проверки повтора
        for(int j = 0; j < str.length(); j++){
            //Если строка прохода совпадает с проверочной строкой, то true
            if(str[j] == c){
                found = true;
                break;
            }
        }
        //Если символ не встретился, то добавляем в str
        if(found == false){
            str += c;
        }
    }
    //Вывод готовой строки
    cout << "\nOutput: " << str;
}

int main(){
    //Переменная
    string stroka;
    //Ввод строки
    cout << "String: ";
    //Принимает строку с пробелами
    getline(cin, stroka);
    //Вывод исходной строки
    cout << "Input: " << stroka;
    
    //Применение функции и вывод готовой строки
    Output(stroka);
    return 0;
}