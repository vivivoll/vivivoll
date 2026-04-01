#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape{
private:
    double area_shape;
    double perimetr;

public:
    //Возврат площади
    virtual double area() const{
        return area_shape;
    }

    //Возврат периметра
    virtual double perimetr_shape() const{
        return perimetr;
    }

    //Вывод информации о фигуре
    virtual void printinfo() const{
        cout << "Площадь фигуры: " << area() << endl;
        cout << "Периметр фигуры: " << perimetr_shape() << endl;
    }

    //Деструктор
    virtual ~Shape() = default;
};

//Производный класс Circle
class Circle : public Shape{
private:
    double radius_circle;

public: 

    //Конструктор
    Circle(double r) : radius_circle(r) {}

    //Площадь
    virtual double area_circle(){
        double area = M_PI * pow(radius_circle, 2);
        return area;
    }
    //Периметр
    virtual double perimetr_circle(){
        double perimetr = 2 * M_PI * radius_circle;
        return perimetr;
    }
};

//Производный класс Rectangle
class Rectangle: public Shape{
private:
    //Стороны прямоугольника
    double storona_1;
    double storona_2;

public:

    //Конструктор
    Rectangle(double s_1, double s_2) : storona_1(s_1), storona_2(s_2) {}

    //Площадь
    virtual double area_rectangle(){
        double area = storona_1 * storona_2;
        return area;
    }

    //Периметр
    virtual double perimetr_rectangle(){
        double perimetr = (storona_1 * 2) + (storona_2 * 2);
        return perimetr;
    }
};

//Производный класс Triangle
class Triangle : public Shape{
private:
    //Стороны треугольника
    double storona_1;
    double storona_2;
    double storona_3;

public:

    //Конструктор
    Triangle(double s_1, double s_2, double s_3) : storona_1(s_1), storona_2(s_2), storona_3(s_3) {}

    //Площадь
    virtual double area_triangle(){
        double p = (storona_1 + storona_2 + storona_3) / 2.0;
        double area = sqrt(p * (p - storona_1) * (p - storona_2) * (p - storona_3));
        return area;
    }

    //Периметр
    virtual double perimetr_triangle(){
        double perimetr = storona_1 = storona_2 + storona_3;
        return perimetr;
    }
};





int main(){
    setlocale(LC_ALL, "ru");

    //Создание фигур и вывод информации о них
    Circle cir(2.0);
    cir.printinfo();
    cout << endl;

    Rectangle rec(2.0, 3.0);
    rec.printinfo();
    cout << endl;

    Triangle tri(4.0, 5.0, 6.0);
    tri.printinfo();
    cout << endl;

    

    return 0;
}