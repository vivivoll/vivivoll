#include <iostream>
using namespace std;

//типизированное пееречисление цветов
enum TrafficLight{
    RED,
    YELLOW,
    GREEN
};

//функция для смены цвета на следующий
TrafficLight NextLight(TrafficLight current){
    switch(current){
        case RED: return YELLOW;
        case YELLOW: return GREEN;
        case GREEN: return RED; 
    }
}

//функция для вывода текущего цвета
string Color(TrafficLight light){
    switch(light){
        case RED: return "Красный";
        case YELLOW: return "Желтый";
        case GREEN: return "Зеленый";
        default: return "Ошибка!";
    }
}

int main(){
    setlocale(LC_ALL, "ru");

    //текущий цвет;
    TrafficLight light = RED;

    for(int i = 0; i < 10; i++){
        cout << "Цвет: " << Color(light) << endl;
        light = NextLight(light);
    }

    return 0;
}