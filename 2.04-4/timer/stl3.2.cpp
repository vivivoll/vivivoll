#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string toUpper(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'а' && s[i] <= 'я') {
            s[i] = s[i] - 'а' + 'А';  //из маленькрй делает большую
        }
        //отдельно буква ё
        else if (s[i] == 'ё') {
            s[i] = 'Ё';
        }
    }
    return s;
}

int main() {
    setlocale(LC_ALL, "ru");

    cout << "=== ЗАДАНИЕ 3.2 ===" << endl;

    vector<string> names = { "Анна", "Александр", "Макс", "Елена",
                            "Боб", "Владислав", "Лия", "Том", "Мария", "Кристина" };

    cout << "\n1. Исходный список: ";
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << " ";
    }
    cout << endl;

    //от короткого к длинному
    sort(names.begin(), names.end(), [](string a, string b) {
        return a.length() < b.length();
        });

    cout << "\n2. После сортировки по длине: ";
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << "(" << names[i].length() << ") ";
    }
    cout << endl;

    //удаление имен короче 4 букв
    auto newEnd = remove_if(names.begin(), names.end(), [](string name) {
        return name.length() < 4;
        });
    names.erase(newEnd, names.end());

    cout << "\n3. После удаления коротких (короче 4): ";
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << " ";
    }
    cout << endl;

    //преобразуем в верхний регистр
    for (int i = 0; i < names.size(); i++) {
        names[i] = toUpper(names[i]);
    }

    //вывод
    cout << "\n4. Конечный результат (все в верхнем регистре): ";
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << " ";
    }
    cout << endl << endl;

    return 0;
}