#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    FILE* source = fopen("source.txt", "r");
    FILE* dest = fopen("result.txt", "w");

    if (!source || !dest) {
        cout << "Ошибка при открытии файлов.\n";
        return 1;
    }

    char symbol;
    while ((symbol = fgetc(source)) != EOF) {
        if (symbol == '0')
            symbol = '1';
        else if (symbol == '1')
            symbol = '0';
        fputc(symbol, dest);
    }

    fclose(source);
    fclose(dest);
    cout << "Файл преобразован.\n";
    return 0;
}