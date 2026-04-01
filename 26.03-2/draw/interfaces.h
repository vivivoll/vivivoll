#pragma once
#include <string>

using namespace std;

// Абстрактный класс 
class Drawable {
public:
    virtual void draw() const = 0;
    virtual ~Drawable() {}
};

// Абстрактный класс 
class Serializable {
public:
    virtual string serialize() const = 0;
    virtual ~Serializable() {}
};

// Конкретные классы
class Circle : public Drawable, public Serializable {
private:
    double x, y, radius;
public:
    Circle(double x, double y, double r);
    void draw() const override;
    string serialize() const override;
};

class Rectangle : public Drawable, public Serializable {
private:
    double x, y, width, height;
public:
    Rectangle(double x, double y, double w, double h);
    void draw() const override;
    string serialize() const override;
};