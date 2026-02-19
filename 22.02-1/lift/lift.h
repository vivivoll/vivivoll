#pragma once
#include <iostream>

class Lift {
private:
    int minFloor;       //нижний этаж
    int maxFloor;       //верхний этаж
    int currentFloor;   //текущий этаж
    bool isWorking;     //состояние лифта

public:
    Lift() : minFloor(1), maxFloor(10), currentFloor(1), isWorking(false) {}

    //конструктор с диапазоном
    Lift(int minF, int maxF)
        : minFloor(minF), maxFloor(maxF), currentFloor(minF), isWorking(false)
    {
        //если min больше max то меняем местами
        if (minFloor > maxFloor) {
            int temp = minFloor;
            minFloor = maxFloor;
            maxFloor = temp;
        }
    }

    //геттеры 
    inline int  getMinFloor()     const { return minFloor; }
    inline int  getMaxFloor()     const { return maxFloor; }
    inline int  getCurrentFloor() const { return currentFloor; }
    inline bool isOn()            const { return isWorking; }

    //установка диапазона этажей
    void setRange(int minF, int maxF);

    //вкл лифт
    void turnOn();

    //выкл лфит
    void turnOff();

    //вызов лифт
    bool call(int floor);
};