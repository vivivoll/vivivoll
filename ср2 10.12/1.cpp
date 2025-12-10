#include <iostream>
using namespace std;

//Указатель
char *str;

int main(){
    setlocale(LC_ALL, "ru");
    
    //Строка
    str = "HELLO WORLD";
    //Цикл выполняется пока n не окажется в конце строки
    for(int i = 0; str[i] != '\0'; i++){
        //Условие для выполнения табуляции в пробелах
        if(str[i] == ' '){
            str[i] = '\t';
        }
    }
    //Вывод результата
    cout << str;

    return 0;
}