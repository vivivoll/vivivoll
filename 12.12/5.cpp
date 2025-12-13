#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");
    //Строка
    char str[100];
    //Символ для поиска
    char symbol;
    //Счетчик
    int count = 0;
    //Ввод строки
    cout << "Введите строку: ";
    cin >> str;
    //Ввод символа для поиска
    cout << "Введите символ для поиска: ";
    cin >> symbol;
    //Цикл для нахождения символа в строке
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == symbol){
            count++;
        }
    }
    //Вывод счетчика символов строки
    cout << "Кол-во символа " << symbol << ": " << count;
    return 0;
}