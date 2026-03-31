#include <string>
#include <iostream>
#include "book.h"
using namespace std;

//С параметрами
Book::Book(const string& t, const string& a, int y) : title(t), author(a), year(y) {
    cout << "Создана книга: " << title << endl;
}

//Метод вывода
void Book::print() const {
    cout << title << " " << author << ", " << year << endl;
}

//Геттер
string Book::getTitle() const {
    return title;
}

//С параметрами через explicit
Library::Library(const string& libraryName) : name(libraryName), count(0) {

    //Обнуление массива
    for (int i = 0; i < MAX_BOOKS; ++i) {
        books[i] = nullptr;
    }
    cout << "Создана библиотека: " << name << endl;
}

//Деструктор
Library::~Library()
{
    //Обнуление указателей
    for (int i = 0; i < count; ++i) {
        books[i] = nullptr;
    }
    count = 0;
    cout << "Библиотека " << name << " закрыта" << endl;
}

//Добавляем книги
bool Library::addBook(Book* book)
{
    if (!book) {
        return false;
    }

    if (count >= MAX_BOOKS) {
        cout << "Библиотека заполнена" << endl;
        return false;
    }

    books[count] = book;
    count++;

    cout << "Добавлена книга: " << book->getTitle() << endl;
    return true;
}

//Метод вывода
void Library::print() const
{
    cout << "Библиотека" << endl;

    if (count == 0) {
        cout << "Нету книг" << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        cout << " ";
        books[i]->print();
    }
    cout << endl;
}