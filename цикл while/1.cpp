#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int number = 455;
    int num;
    int again = 0;


    while (true) {
        cout << "Введите число от 1 до 500\n";
        cin >> num;

        if (num == 0) {
            cout << "Неккоректный ввод";
            break;
        }

        if (num > number) {
            cout << "\nЗадуманное число меньше\n";
            again++;
        }
        else if (num < number) {
            cout << "\nЗадуманное число больше\n";
            again++;
        }
        else {
            cout << "\nВы отгадали число. Количество попыток: " << again;
        }
    }

    return 0;
}
