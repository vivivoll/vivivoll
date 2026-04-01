#pragma once
#include <iostream>
#include <string>
using namespace std;

//Базовый класс
class Employee {
protected:
    string name;

public:
    Employee(const std::string& n) : name(n) {}

    virtual double calculateSalary() const = 0;

    virtual void displayInfo() const {
        cout << "Employee: " << name << endl;
    }
    virtual ~Employee() = default;
};

//Manager
class Manager : public Employee {
    double fixedSalary;

public:
    Manager(const std::string& n, double salary) : Employee(n), fixedSalary(salary) {}

    double calculateSalary() const override {
        return fixedSalary;
    }

    void displayInfo() const override {
        cout << "Manager: " << name << "\n";
    }
};

//Engineer
class Engineer : public Employee {
    double hourlyRate;
    int hours;

public:
    Engineer(const std::string& n, double rate, int h) : Employee(n), hourlyRate(rate), hours(h) {}

    double calculateSalary() const override {
        return hourlyRate * hours;
    }

    void displayInfo() const override {
        cout << "Engineer: " << name << hours << hourlyRate << endl;
    }
};

//SalesPerson
class SalesPerson : public Employee {
    double baseSalary;
    double salesAmount;
    double commissionRate;

public:
    SalesPerson(const string& n, double base, double sales, double rate) : Employee(n), baseSalary(base), salesAmount(sales), commissionRate(rate) {}

    double calculateSalary() const override {
        return baseSalary + salesAmount * commissionRate;
    }

    void displayInfo() const override {
        cout << "SalesPerson: " << name << baseSalary << " + " << commissionRate * 100 << salesAmount << ")\n";
    }
};