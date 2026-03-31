#pragma once
#include <string>
#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    //С параметрами
    Book(const std::string& t, const string& a, int y);

    //Метод вывода
    void print() const;

    //Геттер
    string getTitle() const;
};

//////////////////

class Library {
private:
    string name;
    static const int MAX_BOOKS = 100;          
    Book* books[MAX_BOOKS];                 
    int count;   

    // Запрет копирования
    Library(const Library&) = delete;

public:
    //С параметрами через explicit
    explicit Library(const string& libraryName);
    
    //Деструктор
    ~Library();

    //Добавляем книги
    bool addBook(Book* book);

    //Метод вывода
    void print() const;
};