#include <string>
#include <iostream>
#include "book.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    //Создание объектов книги
    Book b1("Война и мир", "Лев Толстой", 1869);
    Book b2("Мастер и Маргарита", "Михаил Булгаков", 1967);
    
    //Создание библиотеки
    Library lib("Библиотека");

    //Добавление книг в библиотеку
    lib.addBook(&b1);
    lib.addBook(&b2);

    //Вывод книг в библиотеке
    lib.print();

    return 0;
}