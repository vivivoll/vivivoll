#include <iostream>
using namespace std;
//Функция для определения счастливого числа
bool HappyNumber(int a){
    int one = a / 100000;
    int two = a / 10000 % 10;
    int three = a / 1000 % 10;
    int four = a / 100 % 10;
    int five = a / 10 % 10;
    int six = a % 10;

    if(one + two + three == four + five + six){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    setlocale(LC_ALL, "ru");

    if(HappyNumber(123321)){
        cout << "Счастливое число!";
    }
    else{
        cout << "Несчастливое число!";
    }

    return 0;
}
