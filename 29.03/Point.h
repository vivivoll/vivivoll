#pragma once
#include <iostream>
#include <string>
using namespace std;

class Point{
private:
    int x;
    int y;
    static int pointCount;

public:
    Point();
    Point(int xx, int yy);
    Point(const Point& other);
    ~Point();
    int getX() const;
    int getY() const;
    static int getPointCount(){
        return pointCount;
    }

    int distance() const;
    //перегрузки операторов
    bool operator==(const Point& other);
    bool operator!=(const Point& other);
    friend ostream& operator<<(ostream& os, const Point& point);
    friend istream& operator>>(istream& is, Point& point);
};

//2
class Vehicle{
private:
    string model;
    int year;
    Point position;
    static int totalVehicles;

public:
    Vehicle(const string& m, int y, const Point& p);
    Vehicle(const Vehicle& other);
    virtual ~Vehicle();

    //виртуальные методы
    virtual double getMaxSpeed() const;
    virtual void print() const;
    void move(const Point& new_p);
    explicit Vehicle(const string& m);
};

//3
class Car : public Vehicle {
private:
    int doors;

public:
    Car(const string& m, int y, const string &p, int d);
    double getMaxSpeed() const;
    void print() const;
};