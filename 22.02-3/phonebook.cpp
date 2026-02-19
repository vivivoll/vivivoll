#include "phonebook.h"
#include <iostream>

using namespace std;

//реализация через класс Contact
//пустые поля
Contact::Contact()
    : fio(""), home_phone(""), work_phone(""), description("") {
}

//заполнение
Contact::Contact(const string& f, const string& hp, const string& wp, const string& desc)
    : fio(f), home_phone(hp), work_phone(wp), description(desc) {
}

//деконструктор
Contact::~Contact() { 
}

//добавить имя
void Contact::setFIO(const string& f) {
    fio = f;
}

//добавить домашний телефон
void Contact::setHomePhone(const string& hp) {
    home_phone = hp;
}

//добавить рабочий телефон
void Contact::setWorkPhone(const string& wp) {
    work_phone = wp;
}

//добавить примечания
void Contact::setDescription(const string& desc) {
    description = desc;
}

//вывод контакта
void Contact::print() const {
    cout << "ФИО:           " << fio << endl;
    cout << "Дом. телефон:  " << (home_phone.empty() ? "-" : home_phone) << endl;
    cout << "Раб. телефон:  " << (work_phone.empty() ? "-" : work_phone) << endl;
    cout << "Примечание:    " << (description.empty() ? "-" : description) << endl;
}

//поиск по фио
bool Contact::matchesFIO(const string& search) const {
    return fio == search;
}

//реализация методов класса PhoneBook
phonebook::phonebook() : count(0) {
}

//добавить контакт
bool phonebook::add(const Contact& c) {
    if (isFull()) {
        cout << "Телефонная книга переполнена\n";
        return false;
    }
    contacts[count] = c;
    count++;
    cout << "Контакт добавлен\n";
    return true;
}

//удалание контакта
bool phonebook::remove(const string& fio) {
    for (int i = 0; i < count; ++i) {
        if (contacts[i].getFIO() == fio) {
            for (int j = i; j < count - 1; ++j) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            cout << "Контакт удалён.\n";
            return true;
        }
    }
    cout << "Контакт не найден.\n";
    return false;
}

//поиск контакта
void phonebook::search(const string& fio) const {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (contacts[i].matchesFIO(fio)) {
            contacts[i].print();
            found = true;
        }
    }
    if (!found) {
        cout << "Ничего не найдено\n";
    }
}

//показать кол-во контактов
void phonebook::showAll() const {
    if (count == 0) {
        cout << "Телефонная книга пуста.\n";
        return;
    }

    cout << "Записей в книге: " << count << "\n";
    for (int i = 0; i < count; ++i) {
        cout << "[" << (i + 1) << "]\n";
        contacts[i].print();
    }
}

//размер телефонной книжки
int phonebook::size() const {
    return count;
}

//полнота телефонной книжки
bool phonebook::isFull() const {
    return count >= MAX_SIZE;
}