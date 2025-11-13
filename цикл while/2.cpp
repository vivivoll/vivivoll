#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int rubl = 1;
    int dollar = 80;
    int euro = 90;

    int answer = 0;

    cout << "\nКОНВЕРТЕР ВАЛЮТ\n";

    while (true) {
        cout << "\nВыберите действие:\n1.Конвертировать\n2.Выход\n";
        cin >> answer;

        if (answer == 2) {
            cout << "Выход из программы.\n";
            break;
        }

        if (answer == 1) {
            int first, second;
            int amount, result;
          
            cout << "Выберите валюту, которую хотите конвертировать: \n";
            cout << "1.Рубль\n2.Доллар\n3.Евро\n4.Выход\n";
            cin >> first;
            
            if (first != 4) {
                
                cout << "Выберите валюту, в которую будет проходить конвертация: \n";
                cout << "1.Рубль\n2.Доллар\n3.Евро\n4.Выход\n";
                cin >> second;

                if (second != 4) { 
                    cout << "Введите сумму: ";
                    cin >> amount;
                    
                    int RUB;
                    if (first == 1) RUB = amount;
                    else if (first == 2) RUB = amount * dollar;
                    else if (first == 3) RUB = amount * euro;

                    if (second == 1) result = RUB;
                    else if (second == 2) result = RUB / dollar;
                    else if (second == 3) result = RUB / euro;

                    cout << "Результат: " << result << "\n";
                }
            }
        }
        else {
            cout << "Некорректный выбор, попробуйте снова.\n";
        }
    }

    return 0;
}
