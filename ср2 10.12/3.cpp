#include <iostream>
using namespace std;
//Указатель
char *str;

int main(){
    setlocale(LC_ALL, "ru");
    //Строка
    str = "Hello World";
    //Счетчик пробелов
    int count = 0;
    //Цикл для подсчета пробелов
    for(int i = 0; str[i] != 0; i++){
        //Условие для проверки наличия пробела
        if(str[i] == ' '){
            count++;
        }
    }
    //Вывод результата(Добавляем к счетчику +1 чтобы получилось кол-во слов)
    cout << "Кол-во слов: " << count + 1 << endl;
    return 0;
}