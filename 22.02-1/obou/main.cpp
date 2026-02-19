#include <iostream>
#include "obou.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    Apartment apartment;

    //ввод кол комнат
    int numRooms;
    cout << "Сколько комнат будет? ";
    cin >> numRooms;
    cin.ignore();

    //проверка на макс комнат
    if (numRooms > MAX_ROOMS) {
        cout << "Максимум " << MAX_ROOMS << " комнат. Будет использовано " << MAX_ROOMS << ".\n";
        numRooms = MAX_ROOMS;
    }

    for (int i = 1; i <= numRooms; ++i) {
        cout << "\nКомната " << i << ":\n";

        string roomName;
        double length, width, height;
        char ceilingAnswer;

        cout << "Название комнаты: ";
        getline(cin, roomName);

        cout << "Длина (м): "; 
        cin >> length;
        cout << "Ширина (м): "; 
        cin >> width;
        cout << "Высота (м): "; 
        cin >> height;
        cout << "Клеить потолок?: "; 
        cin >> ceilingAnswer;
        cin.ignore();

        bool paintCeiling = (ceilingAnswer == 'да');

        Room room(roomName, length, width, height, paintCeiling);

        if (!apartment.addRoom(room)) {
            cout << "Больше комнат добавить нельзя.\n";
            break;
        }
    }

    //ввод видов обоев
    int numTypes;
    cout << "\nСколько разных видов обоев планируете? ";
    cin >> numTypes;
    cin.ignore();

    //проверка на макс обоев
    if (numTypes > MAX_ROLLS) {
        cout << "Максимум " << MAX_ROLLS << " видов. Будет использовано " << MAX_ROLLS << ".\n";
        numTypes = MAX_ROLLS;
    }

    for (int i = 1; i <= numTypes; ++i) {
        cout << "\nВид обоев " << i << ":\n";

        string rollName;
        double rollWidth, rollLength, price;

        cout << "Название: ";
        getline(cin, rollName);

        cout << "Ширина рулона (м): "; 
        cin >> rollWidth;
        cout << "Длина рулона (м):  "; 
        cin >> rollLength;
        cout << "Цена за рулон (₽): "; 
        cin >> price;
        cin.ignore();

        WallpaperRoll roll(rollName, rollWidth, rollLength, price);

        if (!apartment.addRoll(roll)) {
            cout << "Больше видов обоев добавить нельзя.\n";
            break;
        }
    }

    //вывод
    cout << "РЕЗУЛЬТАТ:\n";
    apartment.printAllRooms();
    cout << "\n";
    apartment.printAllRolls();
    cout << "\n";
    apartment.calculateWallpapers();

    return 0;
}