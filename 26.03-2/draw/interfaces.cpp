#include <iostream>
#include "interfaces.h"
#include <string>
using namespace std;


Circle::Circle(double x, double y, double r) : x(x), y(y), radius(r) {}

void Circle::draw() const {
    cout << "Рисуем круг в " << x << "," << y << " радиус " << radius << endl;
}

string Circle::serialize() const {
    return "Circle " + to_string(x) + " " + to_string(y) + " " + to_string(radius);
}

// ==================== Rectangle ====================
Rectangle::Rectangle(double x, double y, double w, double h) 
    : x(x), y(y), width(w), height(h) {}

void Rectangle::draw() const {
    cout << "Рисуем прямоугольник в (" << x << "," << y << ") ширина=" 
         << width << " высота=" << height << endl;
}

string Rectangle::serialize() const {
    return "Rectangle " + to_string(x) + " " + to_string(y) + " " 
           + to_string(width) + " " + to_string(height);
}