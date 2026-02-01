#pragma once
#include <string>
#include <vector>

struct Song {
    std::string title;      //название песни
    std::string author;     //автор текста
    std::string year;       //год создания
    std::string lyrics;     //текст песни
};

struct Catalog {
    std::vector<Song> songs;  //список песен
};

//функции для работы с каталогом
void addSong(Catalog& catalog);                   //добавление песни
void deleteSong(Catalog& catalog);                //удаление
void editSong(Catalog& catalog);                  //изменение
void displaySong(const Catalog& catalog);         //показать текст
void saveSongToFile(const Catalog& catalog);      //сохранить текст в файл
void findSongsByAuthor(const Catalog& catalog);   //поиск по автору
void findSongsByWord(const Catalog& catalog);     //поиск по слову
void displayAllSongs(const Catalog& catalog);     //показать все песни
void clearInputBuffer();                          //очистка буфета ввода