//1
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    
    cout << "Stroka: ";
    getline(cin, text);         //Ввод строки
    
    int count = 0;   //Счетчик
    while (text[count] != '\0') { //Цикл: пока элемент строки не дошел до конца, прибавляем счетчик
        count++;
    }
    
    cout << "Stroka: " << text << " = " << count << " symbols" << endl; //Вывод результата
    
    return 0;
}
*/
//2
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;

    cout << "Введите строку: ";     //Ввод строки
    getline(cin, text);

    int glasniy = 0;                //Счетчик гласных букв

    for (int i = 0; text[i] != '\0'; i++) {     //Цикл: пока элемент строки не дошел до конца, провееряется условие
        char c = text[i];

        if (c == 'a' || c == 'A' ||
            c == 'e' || c == 'E' ||         //Условие: если элемент строки равен гласной, то прибавляем счетчик гласных
            c == 'i' || c == 'I' ||
            c == 'o' || c == 'O' ||
            c == 'u' || c == 'U' ||
            c == 'y' || c == 'Y') {
            glasniy++;
        }
    }

    cout << "Glasniy symbols: " << glasniy << endl;  //Вывод результата

    return 0;
}