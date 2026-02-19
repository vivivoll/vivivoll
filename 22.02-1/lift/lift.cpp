#include "Lift.h"
#include <iostream>

using namespace std;

//установка диапазона этажей
void Lift::setRange(int minF, int maxF) {
    //если min больше max то меняем местами 
    if (minF > maxF) {
        int temp = minF;
        minF = maxF;
        maxF = temp;
    }

    minFloor = minF;
    maxFloor = maxF;

    //проверка на этаж
    if (currentFloor < minFloor || currentFloor > maxFloor) {
        currentFloor = minFloor;
    }

    cout << "Диапазон этажей установлен: от " << minFloor << " до " << maxFloor << endl;
}

//вкл лифт
void Lift::turnOn() {
    isWorking = true;
    cout << "Лифт включён." << endl;
}

//выкл лифт
void Lift::turnOff() {
    isWorking = false;
    cout << "Лифт выключен." << endl;
}

//вызов лифт
bool Lift::call(int floor) {
    if (!isWorking) {
        cout << "Лифт выключен — вызов невозможен" << endl;
        return false;
    }

    if (floor < minFloor || floor > maxFloor) {
        cout << "Этаж " << floor << " недоступен (диапазон: " << minFloor << "–" << maxFloor << ")" << endl;
        return false;
    }

    currentFloor = floor;
    cout << "Лифт прибыл на этаж " << currentFloor << endl;
    return true;
}