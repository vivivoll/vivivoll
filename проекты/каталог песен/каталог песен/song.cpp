#include "song.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>

//очистка буфера ввода
void clearInputBuffer() {
    std::cin.clear();
    //игнор оставшихся символов до конца строки
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//добавление новой песни
void addSong(Catalog& catalog) {
    Song newSong;

    std::cout << "\n=== Добавление новой песни ===\n";

    std::cout << "Введите название песни: ";
    std::getline(std::cin, newSong.title);

    std::cout << "Введите автора текста: ";
    std::getline(std::cin, newSong.author);

    std::cout << "Введите год создания (или оставьте пустым, если неизвестен): ";
    std::getline(std::cin, newSong.year);

    int choice;
    std::cout << "\nВыберите способ ввода текста:\n";
    std::cout << "1. Ввести с клавиатуры\n";
    std::cout << "2. Загрузить из файла\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;
    clearInputBuffer();

    if (choice == 1) {
        std::cout << "Введите текст песни (для завершения введите строку с точкой):\n";
        std::string line;
        while (true) {
            std::getline(std::cin, line);
            if (line == ".") break;
            newSong.lyrics += line + "\n";
        }
    }
    else if (choice == 2) {
        std::string filename;
        std::cout << "Введите имя файла для загрузки текста: ";
        std::getline(std::cin, filename);

        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Ошибка: не удалось открыть файл." << std::endl;
            return;
        }

        //для чтения файла построчно
        std::string line;
        while (std::getline(file, line)) {
            newSong.lyrics += line + "\n";
        }
        file.close();
    }
    else {
        std::cout << "Неверный выбор." << std::endl;
        return;
    }

    catalog.songs.push_back(newSong);
    std::cout << "Песня успешно добавлена в каталог!" << std::endl;
}

//отображение всех песен
void displayAllSongs(const Catalog& catalog) {
    if (catalog.songs.empty()) {
        std::cout << "Каталог пуст." << std::endl;
        return;
    }

    std::cout << "Список песен в каталоге:\n";
    for (int i = 0; i < catalog.songs.size(); ++i) {
        std::cout << i + 1 << ". " << catalog.songs[i].title
            << " (автор: " << catalog.songs[i].author << ")";
        if (!catalog.songs[i].year.empty()) {
            std::cout << ", год: " << catalog.songs[i].year;
        }
        std::cout << std::endl;
    }
}

//выбор песни по индексу
int selectSongIndex(const Catalog& catalog) {
    if (catalog.songs.empty()) {
        std::cout << "Каталог пуст." << std::endl;
        return -1;
    }

    displayAllSongs(catalog);

    int index;
    std::cout << "Введите номер песни: ";
    std::cin >> index;

    if (std::cin.fail() || index < 1 || index > catalog.songs.size()) {
        std::cout << "Ошибка: неверный номер песни." << std::endl;
        clearInputBuffer();
        return -1;
    }

    clearInputBuffer();
    return index - 1;
}

//удаление песни
void deleteSong(Catalog& catalog) {
    int index = selectSongIndex(catalog);
    if (index == -1) return;

    catalog.songs.erase(catalog.songs.begin() + index);
    std::cout << "Песня удалена из каталога." << std::endl;
}

//изменение существующей песни
void editSong(Catalog& catalog) {
    int index = selectSongIndex(catalog);
    if (index == -1) return;

    Song& song = catalog.songs[index];

    std::cout << "\nЧто вы хотите изменить?\n";
    std::cout << "1. Название\n";
    std::cout << "2. Автора\n";
    std::cout << "3. Год создания\n";
    std::cout << "4. Текст песни\n";
    std::cout << "Ваш выбор: ";

    int choice;
    std::cin >> choice;
    clearInputBuffer();

    switch (choice) {
    case 1:
        std::cout << "Введите новое название: ";
        std::getline(std::cin, song.title);
        break;
    case 2:
        std::cout << "Введите нового автора: ";
        std::getline(std::cin, song.author);
        break;
    case 3:
        std::cout << "Введите новый год создания: ";
        std::getline(std::cin, song.year);
        break;
    case 4: {
        song.lyrics = "";
        std::cout << "Введите новый текст песни (для завершения введите строку с точкой):\n";
        std::string line;
        while (true) {
            std::getline(std::cin, line);
            if (line == ".") break;
            song.lyrics += line + "\n";
        }
        break;
    }
    default:
        std::cout << "Неверный выбор." << std::endl;
    }
}

//отображение текста выбранной песни
void displaySong(const Catalog& catalog) {
    int index = selectSongIndex(catalog);
    if (index == -1) return;

    const Song& song = catalog.songs[index];
    std::cout << "\n=== Текст песни ===\n";
    std::cout << "Название: " << song.title << std::endl;
    std::cout << "Автор: " << song.author << std::endl;
    if (!song.year.empty()) {
        std::cout << "Год создания: " << song.year << std::endl;
    }
    std::cout << "Текст песни:\n" << song.lyrics << std::endl;
}

//сохранение текста песни в файл
void saveSongToFile(const Catalog& catalog) {
    int index = selectSongIndex(catalog);
    if (index == -1) return;

    std::string filename;
    std::cout << "Введите имя файла для сохранения: ";
    std::getline(std::cin, filename);

    const Song& song = catalog.songs[index];
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось создать файл." << std::endl;
        return;
    }

    file << song.lyrics;
    file.close();
    std::cout << "Текст песни успешно сохранен в файл." << std::endl;
}

//поиск песен по автору
void findSongsByAuthor(const Catalog& catalog) {
    if (catalog.songs.empty()) {
        std::cout << "Каталог пуст." << std::endl;
        return;
    }

    std::string author;
    std::cout << "Введите имя автора для поиска: ";
    std::getline(std::cin, author);

    bool found = false;
    std::cout << "\n=== Результаты поиска ===\n";

    for (int i = 0; i < catalog.songs.size(); ++i) {
        if (catalog.songs[i].author == author) {
            std::cout << i + 1 << ". " << catalog.songs[i].title;
            if (!catalog.songs[i].year.empty()) {
                std::cout << " (" << catalog.songs[i].year << ")";
            }
            std::cout << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "Песни данного автора не найдены." << std::endl;
    }
}

//поиск песен по слову в тексте
void findSongsByWord(const Catalog& catalog) {
    if (catalog.songs.empty()) {
        std::cout << "Каталог пуст." << std::endl;
        return;
    }

    std::string word;
    std::cout << "Введите слово для поиска в тексте: ";
    std::getline(std::cin, word);

    bool found = false;
    std::cout << "\n=== Результаты поиска ===\n";

    for (int i = 0; i < catalog.songs.size(); ++i) {
        std::string lyricsLower = catalog.songs[i].lyrics;
        std::string wordLower = word;

        std::transform(lyricsLower.begin(), lyricsLower.end(), lyricsLower.begin(), ::tolower);
        std::transform(wordLower.begin(), wordLower.end(), wordLower.begin(), ::tolower);

        if (lyricsLower.find(wordLower) != std::string::npos) {
            std::cout << i + 1 << ". " << catalog.songs[i].title
                << " (автор: " << catalog.songs[i].author << ")";
            if (!catalog.songs[i].year.empty()) {
                std::cout << ", год: " << catalog.songs[i].year;
            }
            std::cout << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "Песни с таким словом в тексте не найдены." << std::endl;
    }
}