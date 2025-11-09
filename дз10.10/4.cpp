#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int sum = 0;

    for (int i = 1; i <=9; i++){
        int choose;
        cout << "Подрбрасывание:\n1.Орел\n2.Решка\nОтвет: ";
        cin >> choose;

        if (choose == 1){
            sum++;
        }
    }

    if (sum % 2 == 0){
        cout << "Положительное";
    }
    else{
        cout << "Отрицательное";
    }



    return 0;
}