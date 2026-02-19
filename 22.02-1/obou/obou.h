#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

//макс кол комнат и обоев
const int MAX_ROOMS = 20;
const int MAX_ROLLS = 10;

//класс комната
class Room {
private:
    string name;       
    double length;     
    double width;
    double height;      
    bool paintCeiling;  

public:
    Room(); //конструктор по умолчанию
    Room(string n, double l, double w, double h, bool ceiling);

    double wallArea() const; //площадь стен
    double ceilingArea() const; //площадь потолка
    double totalAreaToCover() const; //общая площадь для оклейки

    string getName() const; //получить название
    void printInfo() const; //вывести информацию о комнате
};

//класс рулон обоев 
class WallpaperRoll {
private:
    string name;       
    double rollWidth;   
    double rollLength; 
    double price;       

public:
    WallpaperRoll();//конструктор по умолчанию
    WallpaperRoll(string n, double w, double l, double p);

    double rollArea() const;//площадь одного рулона
    double cost(int count) const;//стоимость за указанное количество рулонов

    string getName() const;//получить название
    double getPrice() const;//получить цену за рулон
    void printInfo() const;//вывести информацию о рулоне
};

//класс квартира
class Apartment {
private:
    Room rooms[MAX_ROOMS];         
    int roomCount;                  

    WallpaperRoll rolls[MAX_ROLLS]; 
    int rollCount;                  

public:
    Apartment();//конструктор

    bool addRoom(const Room& room);      // добавить комнату
    bool addRoll(const WallpaperRoll& roll); // добавить вид обоев

    double totalAreaToCover() const;    // посчитать общую площадь для оклейки

    void calculateWallpapers() const;  //основной расчёт количества и стоимости
    void printAllRooms() const;        //вывести все комнаты
    void printAllRolls() const;        //вывести все виды обоев
};