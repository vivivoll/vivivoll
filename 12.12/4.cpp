#include <iostream>
using namespace std;
//Функция замены символов
void Point(char *str, char symbol){
    //Цикл для проверки символов и из замены
    for(int i = 0; str[i] != '\0'; i++){
        //Условие проверки элемента и его замены
        if(str[i] == '.'){
            str[i] = '!';
        }
        cout << str[i];
    }
}

int main(){
    setlocale(LC_ALL, "ru");
    //Строка
    char str[] = "Hello. World.";
    //Вывод исходной строки
    cout << "Исходная строка: " << str << endl;
    //Вывод готовой строки через функцию
    cout << "Замена спец знаков: ";
    Point(str, '!');
    return 0;
}