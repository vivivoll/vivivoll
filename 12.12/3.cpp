#include <iostream>
using namespace std;
//Функция вставки символа в строку
void PasteSymbol(const char *str, int symbol_index, char symbol) {
    //Цикл для вставки символа
    for(int i = 0; str[i] != '\0'; i++) {
        //Условие проверки элемента с символом
        if(i == symbol_index) {
            cout << symbol;
        }
        cout << str[i];
    }
}

int main(){
    setlocale(LC_ALL, "ru");
    //Строка с указателем
    char *str = "Hello";
    //Вывод исходной строки
    cout << "Исходная строка: " << str << endl;
    //Вывод готовой строки через функцию 
    cout << "Строка с вставленным символом: ";
    PasteSymbol(str, 4, 'o');
    return 0;
}