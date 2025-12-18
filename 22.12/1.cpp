#include <iostream>
#include <algorithm> //Подключение библиотеки для reverse
#include <cstring> //Подключение библиотеки для reverse
using namespace std;

int main(){
    //Способ через algorithm
    
    //Переменная для reverse
    string input_1;
    
    //Ввод строки
    cout << "String: ";
    
    //Принимает строку c пробелами;
    getline(cin, input_1);
    
    //Переворот строки
    reverse(input_1.begin(), input_1.end());
    
    //Вывод результата
    cout << "Result algorithm: " << input_1 << endl;


    
    //Способ через цикл
    
    //Максимальный размер строки
    char input[100];

    cout << "String without algorithm: ";
    cin >> input;

    //Цикл для нахождения длины строки: 
    int n = 0; //Счетчик
    while(input[n] != '\0'){
        n++;
    }

    //Цикл для переворота строки
    for(int i = 0; i < n / 2; i++){
        char temp = input[i];
        input[i] = input[n - 1 - i];
        input[n - 1 - i] = temp;
    }
    cout << "String without algorithm: " << input << endl;

    return 0;
}