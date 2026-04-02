#include <iostream>
#include "Point.h"
#include <string>
using namespace std;

Point::Point(){
    x = 0;
    y = 0;
    pointCount++;
}

Point::Point(int xx, int yy) : x(xx), y(yy) {
    pointCount++;
}

Point::Point(const Point& other){
    x = other.x;
    y = other.y;
    pointCount++;
}

Point::~Point(){
    pointCount--;
}

int Point::getX() const{ return x; }
int Point::getY() const{ return y; }

int Point::distance() const{
    return sqrt(x * x + y * y);
}

bool Point::operator==(const Point &other){
    return x == other.x;
    return y == other.y;
}

bool Point::operator!=(const Point& other){
    return x != other.x;
    return y != other.y;
}

ostream& operator<<(ostream& os, const Point& point){
    os << "x: " << point.x << endl;
    os << "y: " << point.y << endl;
}

istream& operator>>(istream& is, Point& point){
    is >> point.x >> point.y;
}

//2
Vehicle::Vehicle(const string& m, int y, const Point& p) : model(m), year(y), position(p){
    totalVehicles++;
}

Vehicle::Vehicle(const Vehicle& other){
    model = other.model;
    year = other.year;
    position = other.position;
    
    totalVehicles++;
}

Vehicle::~Vehicle(){
    totalVehicles--;
}

//виртуальные методы
void Vehicle::print() const{
    cout << model << endl;
    cout << year << endl;
    cout << position << endl;
}

void Vehicle::move(const Point& new_p){

}

explicit Vehicle::Vehicle(const string& m) : model(model), year(2020), position(Point(0,0)) {
    totalVehicles++;
} 