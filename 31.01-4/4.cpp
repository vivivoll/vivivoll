#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    FILE* file = fopen("document.txt", "r");
    if (!file) {
        cout << "Файл отсутствует.\n";
        return 1;
    }

    int charCount = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        charCount++;
    }

    fclose(file);
    cout << "Символов в файле: " << charCount << "\n";
    return 0;
}