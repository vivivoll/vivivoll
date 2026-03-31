#include "house.h"
using namespace std;

//С параметрами
Room::Room(const string& n, int a) : name(n), area(a) {
    cout << "Комната добавлена: " << name << endl;
}

//Деструктор
Room::~Room() {
    cout << "Комната удалена: " << name << endl;
}

//Метод вывода
void Room::print() const {
    cout << "  Комната: " << name << ", площадь " << area << endl;
}

///////////////////////

//С параметрами
House::House(const string& addr) : address(addr), count(0) {
    cout << "Создан дом по адресу: " << address << endl;
}

//Деструктор
House::~House() {
    cout << "Дом разрушен: " << address << endl;
}

//Добавление комнаты
bool House::addRoom(const string& name, int area) {
    if (count >= MAX_ROOMS) {
        cout << "Дом заполнен" << endl;
        return false;
    }

    rooms[count] = Room(name, area);
    count++;
    return true;
}

//Метод вывода
void House::print() const {
    cout << "Дом: " << address << endl;
    
    if (count == 0) {
        cout << "Комнат нет" << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        rooms[i].print();
    }
    cout << endl;
}