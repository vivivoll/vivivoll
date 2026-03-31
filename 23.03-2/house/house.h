#pragma once
#include <iostream>
#include <string>
using namespace std;

class Room {
private:
    string name;
    int area;

public:
    //С параметрами
    Room(const string& n, int a);

    //Деструктор
    ~Room();

    //Метод вывода
    void print() const;
};

///////////////////////

class House {
private:
    string address;
    static const int MAX_ROOMS = 20;
    Room rooms[MAX_ROOMS];     //Композиция
    int count;

    //Запрет копирования
    House(const House& other) = delete;

public:
    //С параметрами
    House(const string& addr);

    //Деструктор
    ~House();

    //Добавление комнаты
    bool addRoom(const string& name, int area);

    //Метод вывода
    void print() const;
};