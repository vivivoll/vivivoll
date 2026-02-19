#include <iostream>
#include "Lift.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "=== Тестирование класса Lift ===\n\n";

    //лифт по умолчанию 
    Lift lift1;
    cout << "Лифт по умолчанию:\n";
    cout << "  Диапазон: " << lift1.getMinFloor() << " – " << lift1.getMaxFloor() << endl;
    cout << "  Текущий этаж: " << lift1.getCurrentFloor() << endl;
    cout << "  Состояние: " << (lift1.isOn() ? "Включён" : "Выключен") << endl << endl;

    //вкл и вызываем
    lift1.turnOn();
    lift1.call(7);
    lift1.call(3);
    lift1.call(12);         
    lift1.call(-1);         

    //выкл и вызываем
    lift1.turnOff();
    lift1.call(5);          

    cout << "\n\n";

    //лифт с другим диапазоном 
    Lift lift2(-3, 12);
    cout << "Лифт с диапазон -3 - 12):\n";
    cout << "  Диапазон: " << lift2.getMinFloor() << " – " << lift2.getMaxFloor() << endl;
    lift2.turnOn();
    lift2.call(-2);
    lift2.call(0);
    lift2.call(15);         

    //меняем диапазон
    lift2.setRange(0, 8);
    lift2.call(6);
    return 0;
}