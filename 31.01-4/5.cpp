#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    FILE* file = fopen("textfile.txt", "r");
    if (!file) {
        cout << "Файл не найден.\n";
        return 1;
    }

    int lineCount = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') lineCount++;
    }

    fclose(file);
    cout << "Строк в файле: " << lineCount + 1 << "\n";
    return 0;
}