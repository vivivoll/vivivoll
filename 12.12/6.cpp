#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");
    //Счетчики букв, цифр и символов
    int stroka = 0;
    int count = 0;
    int symbols = 0;
    //Строка
    char str[100];
    //Ввод строки
    cout << "Введите строку: ";
    cin >> str;

    //Цикл для подсчета цифр и букв
    for(int i = 0; str[i] != '\0'; i++){
        //Условие для проверки заглавной буквы
        if(str[i] >= 'A' && str[i] <= 'Z'){
            stroka++;
        }
        //Условие для проверки строчной буквы
        if(str[i] >= 'a' && str[i] <= 'z'){
            stroka++;
        }
        //Условие для проверки цифры
        if(str[i] >= '0' && str[i] <='9'){
            count++;
        }
        //Условие для проверки символа
        if(str[i] == '+'){
            symbols++;
        }
        //Условие для проверки символа
        if(str[i] == '-'){
            symbols++;
        }
        //Условие для проверки символа
        if(str[i] == '*'){
            symbols++;
        }
        //Условие для проверки символа
        if(str[i] == '/'){
            symbols++;
        }
    }
    //Вывод результатов
    cout << "Nubmer: " << count << endl;
    cout << "String: " << stroka << endl; 
    cout << "Symbols: " << symbols << endl;
    return 0;
}