#include <iostream>
using namespace std;

//типизированное пееречисление координат
enum Direction {
    NORTH = 'N',
    EAST = 'E',
    SOUTH = 'S',
    WEST = 'W'
};

//функция для поворота координаты
void Move(Direction dir, int &x, int &y) {
    switch(dir) {
        case NORTH: y++; break; //^ +1
        case EAST: x++; break; //> +1
        case SOUTH: y--; break; //^ -1
        case WEST: x--; break; //> -1
    }
}

int main(){
    setlocale(LC_ALL, "ru");

    //начальные координаты
    int x = 0;
    int y = 0;

    cout << "Текущие координаты" << endl;
    cout << "x = " << x << " y = " << y << endl; 

    //перемещение координат с помощью функции
    Move(NORTH, x, y);
    cout << "Новые координаты" << endl;
    cout << "x = " << x << " y = " << y << endl;

    Move(EAST, x, y);
    cout << "Новые координаты" << endl;
    cout << "x = " << x << " y = " << y << endl;

    return 0;
}