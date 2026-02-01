#include <iostream>
#include "song.h"

//меню
void displayMenu() {
    std::cout << "\n=== КАТАЛОГ ТЕКСТОВ ПЕСЕН ===\n";
    std::cout << "1. Добавить песню\n";
    std::cout << "2. Удалить песню\n";
    std::cout << "3. Изменить песню\n";
    std::cout << "4. Показать текст песни\n";
    std::cout << "5. Сохранить текст песни в файл\n";
    std::cout << "6. Найти песни по автору\n";
    std::cout << "7. Найти песни по слову в тексте\n";
    std::cout << "8. Показать все песни в каталоге\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите действие: ";
}

int main() {
//для нормального отображения русских букв
#ifdef _WIN32
    system("chcp 1251 > nul");
#endif

    Catalog catalog;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;
        clearInputBuffer();

        switch (choice) {
        case 1:
            addSong(catalog);
            break;
        case 2:
            deleteSong(catalog);
            break;
        case 3:
            editSong(catalog);
            break;
        case 4:
            displaySong(catalog);
            break;
        case 5:
            saveSongToFile(catalog);
            break;
        case 6:
            findSongsByAuthor(catalog);
            break;
        case 7:
            findSongsByWord(catalog);
            break;
        case 8:
            displayAllSongs(catalog);
            break;
        case 0:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор." << std::endl;
        }
    } while (choice != 0);

    return 0;
}