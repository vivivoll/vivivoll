#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    FILE* file = fopen("data.txt", "r");
    if (!file) {
        cout << "Не удалось открыть файл.\n";
        return 1;
    }

    char target;
    cout << "Введите символ для поиска: ";
    cin >> target;

    int wordCount = 0;
    char current, previous = ' ';

    while ((current = fgetc(file)) != EOF) {
        if ((previous == ' ' || previous == '\n' || previous == '\t') && current == target) {
            wordCount++;
        }
        previous = current;
    }

    fclose(file);
    cout << "Найдено слов: " << wordCount << "\n";
    return 0;
}