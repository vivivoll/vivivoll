#include <iostream>
#include "interfaces.h"
#include <string>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    //Создание объектов
    Circle* c = new Circle(5, 5, 10);
    Rectangle* r = new Rectangle(0, 0, 20, 15);


    cout << "Рисование:" << endl;
    c->draw();
    r->draw();


    cout << "Сериализация:" << endl;
    cout << c->serialize() << endl;
    cout << r->serialize() << endl;

    cout << "Удаление" << endl;
    delete c;
    delete r;

    return 0;
}