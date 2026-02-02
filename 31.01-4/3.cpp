#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    const int SIZE = 4;
    const int LEN = 100;
    char lines[SIZE][LEN] = {
        "Пример строки 1",
        "Пример строки 2",
        "Пример строки 3",
        "Пример строки 4"
    };

    FILE* file = fopen("output.txt", "w");
    if (!file) {
        cout << "Ошибка создания файла.\n";
        return 1;
    }

    for (int i = 0; i < SIZE; ++i) {
        fputs(lines[i], file);
        fputc('\n', file);
    }

    fclose(file);
    cout << "Данные записаны.\n";
    return 0;
}