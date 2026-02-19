#pragma once
#include <iostream>
#include <string>

using namespace std;

class Contact {
private:
    string fio;
    string home_phone;
    string work_phone;
    string description;

public:
    //конструкторы
    //по умолчанию
    Contact();
    Contact(const string& f,
        const string& hp = "",
        const string& wp = "",
        const string& desc = "");

    //деструктор
    ~Contact();

    //геттеры
    string getFIO()        const { return fio; }
    string getHomePhone()  const { return home_phone; }
    string getWorkPhone()  const { return work_phone; }
    string getDescription() const { return description; }

    //сеттеры
    void setFIO(const string& f);
    void setHomePhone(const string& hp);
    void setWorkPhone(const string& wp);
    void setDescription(const string& desc);

    void print() const;
    bool matchesFIO(const string& search) const;
};

//класс телефоная книжка
class phonebook {
private:
    static const int MAX_SIZE = 100;
    Contact contacts[MAX_SIZE];
    int count;

public:
    //конструктор
    phonebook();
    bool add(const Contact& c);
    bool remove(const string& fio);
    void search(const string& fio) const;
    void showAll() const;

    int size() const;
    bool isFull() const;
};