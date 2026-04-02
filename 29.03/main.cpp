#include <iostream>
#include <string>
#include "Point.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    Point point_1; 
    cout << point_1 << endl;

    Point point_2(5,4);
    cout << point_2 << endl;

    Point point_3(point_1);
    cout << point_3 << endl; 

    Point::getPointCount();
    cout << endl;

    point_1.distance();
    cout << endl;
    
    point_2.distance();
    cout << endl;
    
    point_3.distance();
    cout << endl;

    cout << (point_1 == point_2 ? "yes" : "no") << endl;
    cout << (point_2 != point_2 ? "yes" : "no") << endl;

    Point point_4;
    cout << point_4 << endl;

    Point point_5;
    cin >> point_5;

    return 0;
}