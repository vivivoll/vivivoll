#include <iostream>
using namespace std;
//Функция для удаления символа
void DeleteSymbols(char *str, char symbol){
    //Цикл для пропуска элемента массива с указанным символом
    for(int i = 0; str[i] != '\0'; i++){
        //Условие проверки элемента с символом
        if(str[i] == symbol){
            continue;
        }
        cout << str[i];
    }
}

int main(){
    setlocale(LC_ALL, "ru");
    //Строка с указателем
    char *str = "Hello World";
    //Вывод исходной строки
    cout << "Исходная строка: " << str << endl;
    //Вывод готовой строки через функцию
    cout << "Строка с удалением символа: ";
    DeleteSymbols(str, 'l');
    return 0;
}