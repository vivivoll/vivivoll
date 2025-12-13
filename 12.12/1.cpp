#include <iostream>
using namespace std;
//Функция для удаления символа
void DeleteSymbol(const char *str, int symbol_index) {
    //Цикл для прохода по символам строки
    for(int i = 0; str[i] != '\0'; i++){
        //Условие проверки элемента с символом
        if(i == symbol_index){
            continue;
        }
        cout << str[i]; 
    }
    cout << endl; 
}

int main(){
    setlocale(LC_ALL, "ru");
    //Строка
    char *str = "Hello World!";
    //Вывод исходной строки
    cout << "Исходная строка: " << str << endl;
    //Вывод строки после удаления 1-го элемента
    cout << "Удаление первого символа: ";
    DeleteSymbol(str, 0); 

    return 0;
}