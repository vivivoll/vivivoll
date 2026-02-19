#include <iostream>
#include "phonebook.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");  

    PhoneBook book;
    int choice;
    string input;

    //меню do-while
    do {
        cout << "\n--- Телефонная книга ---\n";
        cout << "1.Добавить контакт\n";
        cout << "2.Удалить по ФИО\n";
        cout << "3.Найти по ФИО\n";
        cout << "4.Показать все контакты\n";
        cout << "0.Выход\n";
        cout << "-> ";

        cin >> choice;
        cin.ignore(); 

        //выбор действия от пользователя
        switch (choice) {
        case 1: {
            string f, hp, wp, d;
            cout << "ФИО:            "; getline(cin, f);
            cout << "Дом. телефон:   "; getline(cin, hp);
            cout << "Раб. телефон:   "; getline(cin, wp);
            cout << "Примечание:     "; getline(cin, d);

            Contact c(f, hp, wp, d);
            book.add(c);
            break;
        }

        case 2: {
            cout << "Введите ФИО для удаления: ";
            getline(cin, input);
            book.remove(input);
            break;
        }

        case 3: {
            cout << "Введите ФИО для поиска: ";
            getline(cin, input);
            book.search(input);
            break;
        }

        case 4:
            book.showAll();
            break;

        case 0:
            cout << "До свидания\n";
            break;

        default:
            cout << "Неверный выбор.\n";
        }
    } while (choice != 0);

    return 0;
}