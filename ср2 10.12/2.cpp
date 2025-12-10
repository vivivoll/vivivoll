#include <iostream>
using namespace std;
//Указатель
char *str;

int main(){
    setlocale(LC_ALL, "ru");
    //Счетчики букв и цифр
    int stroka = 0;
    int count = 0;
    //Строка
    str = "Password123";

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
    }
    //Вывод результатов
    cout << "Nubmer: " << count << endl;
    cout << "String: " << stroka << endl; 
    return 0;
}