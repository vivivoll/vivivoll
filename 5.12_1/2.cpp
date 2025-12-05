#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");
    
    int x;
    cout << "Введите число: ";      //Получение переменной
    cin >> x;

    int *px = &x;                   //Разыменование переменной(получения ее значения)
    
    if(*px > 0){
        cout << "+";
    }
    else if(*px == 0){
        cout << "0";                //Условие на проверку значения числа (-,0,+)
    }
    else{
        cout << "-";
    }

    return 0;
}