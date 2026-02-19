#include "obou.h"

using namespace std;

//комната
//конструктор по умолчанию
Room::Room()
    : name("Без названия"), length(0), width(0), height(0), paintCeiling(false) {
}

//конструктор с параметрами
Room::Room(string n, double l, double w, double h, bool ceiling)
    : name(n), length(l), width(w), height(h), paintCeiling(ceiling) {
}

//площадь стен 
double Room::wallArea() const {
    double perimeter = 2 * (length + width);
    return perimeter * height;
}

//площадь потолка
double Room::ceilingArea() const {
    return length * width;
}

//общая площадь
double Room::totalAreaToCover() const {
    double s = wallArea();
    if (paintCeiling) s += ceilingArea();
    return s;
}

//название
string Room::getName() const {
    return name;
}

//вывод информации о комнате
void Room::printInfo() const {
    cout << "Комната: " << name << endl;
    cout << "Размеры: " << length << " x " << width << " x " << height << endl;
    cout << "Площадь стен: " << fixed << setprecision(2) << wallArea() << endl;

    if (paintCeiling) {
        cout << "Площадь потолка: " << fixed << setprecision(2) << ceilingArea() << endl;
    }
    cout << "Итого площадь: " << fixed << setprecision(2) << totalAreaToCover() << endl;
}

//обои методы
//конструктор по умолчанию
WallpaperRoll::WallpaperRoll()
    : name("Без названия"), rollWidth(0), rollLength(0), price(0) {
}

//конструктор с параметрами
WallpaperRoll::WallpaperRoll(string n, double w, double l, double p)
    : name(n), rollWidth(w), rollLength(l), price(p) {
}

//площадь одного рулона
double WallpaperRoll::rollArea() const {
    return rollWidth * rollLength;
}

//стоимость за заданное количество рулонов
double WallpaperRoll::cost(int count) const {
    return price * count;
}

//название
string WallpaperRoll::getName() const {
    return name;
}

//цена
double WallpaperRoll::getPrice() const {
    return price;
}

//вывод информации о рулоне
void WallpaperRoll::printInfo() const {
    cout << name << endl;
    cout << "Размер рулона: " << rollWidth << " x " << rollLength << endl;
    cout << "Площадь одного: " << fixed << setprecision(2) << rollArea() << endl;
    cout << "Цена: " << fixed << setprecision(2) << price << endl;
}

//квартира  методы
Apartment::Apartment() : roomCount(0), rollCount(0) {}

//добавление комнаты
bool Apartment::addRoom(const Room& room) {
    //проверка на макс комнат
    if (roomCount >= MAX_ROOMS) {
        cout << "Ошибка: достигнут лимит комнат (" << MAX_ROOMS << ")\n";
        return false;
    }
    rooms[roomCount] = room;
    roomCount++;
    return true;
}

//добавление вида обоев
bool Apartment::addRoll(const WallpaperRoll& roll) {
    //проверка на максимум обоев
    if (rollCount >= MAX_ROLLS) {
        cout << "Ошибка: достигнут лимит видов обоев (" << MAX_ROLLS << ")\n";
        return false;
    }
    rolls[rollCount] = roll;
    rollCount++;
    return true;
}

//общая площадь всех комнат для оклейки
double Apartment::totalAreaToCover() const {
    double sum = 0.0;
    for (int i = 0; i < roomCount; ++i) {
        sum += rooms[i].totalAreaToCover();
    }
    return sum;
}

//расчёт сколько нужно рулонов и сколько стоит
void Apartment::calculateWallpapers() const {
    double totalArea = totalAreaToCover();
    cout << "\nОбщая площадь для оклейки: " << fixed << setprecision(2) << totalArea << "\n";

    for (int i = 0; i < rollCount; ++i) {
        const WallpaperRoll& roll = rolls[i];
        double areaPerRoll = roll.rollArea();

        int needed = (int)ceil(totalArea / areaPerRoll);
        double totalCost = roll.cost(needed);

        cout << "Для вида \"" << roll.getName() << endl;
        cout << " Площадь одного рулона: " << fixed << setprecision(2) << areaPerRoll << endl;
        cout << "Нужно рулонов: " << needed << endl;
        cout << "Стоимость: " << fixed << setprecision(2) << totalCost << endl;
        cout << "\n";
    }
}

//вывод списка всех комнат
void Apartment::printAllRooms() const {
    if (roomCount == 0) {
        cout << "Комнаты не добавлены.\n";
        return;
    }
    cout << "Комнаты (" << roomCount << "):\n";
    for (int i = 0; i < roomCount; ++i) {
        rooms[i].printInfo();
        cout << endl;
    }
}

//вывод списка всех обоев
void Apartment::printAllRolls() const {
    if (rollCount == 0) {
        cout << "Виды обоев не добавлены.\n";
        return;
    }
    cout << "Виды обоев (" << rollCount << "):\n";
    for (int i = 0; i < rollCount; ++i) {
        rolls[i].printInfo();
        cout << endl;
    }
}