#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

//пространство имен 
namespace Geometry{
    //константа пи
    const double PI = 3.14159;
    //вычисления площади круга
    double circleArea(double radius);
    //вычисления площади прямоугольника
    double rectangleArea(double width, double height);
    //вложенное пространство
    namespace Shapes{
        class Circle{
    
        public:
            double area();
            double radius;
        };
    }
}
