#include <iostream>
using namespace std;
//Функция для определения масти и номера карты
void ShowCard(int a, int b){
    switch(a){
        case 6:
        cout << "6";
        break;
        case 7:
        cout << "7";
        break;
        case 8:
        cout << "8";
        break;
        case 9:
        cout << "9";
        break;
        case 10: 
        cout << "10";
        break;
        case 11:
        cout << "Валет";
        break;
        case 12:
        cout << "Дама";
        break;
        case 13:
        cout << "Король";
        break;
        case 14:
        cout << "Туз";
        break;
    }

    cout << "  "; 

    switch(b){
        case 1:
        cout << "Пики";
        break;
        case 2:
        cout << "Крести";
        break;
        case 3:
        cout << "Черви";
        break;
        case 4:
        cout << "Бубни";
        break;
    }
}

int main(){
    setlocale(LC_ALL, "ru");

    ShowCard(12, 4);

    return 0;
}
