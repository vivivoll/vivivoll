#include <iostream>
#include <string>
#include <stdexcept>
#include "Geometry.h"
using namespace std;

//вычисления площиди круга
double Geometry::circleArea(double radius){
    return PI * radius * radius;
}
//вычисления площади прямоугольника
double Geometry::rectangleArea(double width, double height){
    return width * height;
}

double Geometry::Shapes::Circle::area(){
    Geometry::circleArea(radius);
}
