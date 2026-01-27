//1
/*
#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    int n;  //Переменная
    cout << "n = "; //Ввод числа
    cin >> n;

    int sum = 0;    //Счетчик

    for(int i = 1; i <= n; i++){
        sum += i;                   //Цикл: сложение каждого числа до числа, которое задал пользователь
    }

    cout << "Otvet: " << sum; //Вывод результата

    return 0;
}
*/
//2
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int n; //Переменная

    cout << "n = ";
    cin >> n;       //Ввод числа

    for (int i = 1; i <= 10; i++) {       //Цикл: вывод таблицы умножения, пока i<=10
        cout << n << " x " << i << " = " << n * i;
        cout << "\n\n";
    }

    return 0;
}