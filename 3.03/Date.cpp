#include "Date.h"
#include <iostream>
using namespace std;

//Заполнение полей
Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

//Проверки
bool Date::isLeapYear(int y) const {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    if (y % 4 == 0) return true;
    return false;
}

int Date::daysInMonth(int m, int y) const {
    if (m == 2) {
        if (isLeapYear(y)) return 29;
        else return 28;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    return 31;
}

long Date::toDays() const {
    long days = 0;

    for (int y = 1; y < year; y++) {
        if (isLeapYear(y)) days = days + 366;
        else days = days + 365;
    }

    for (int m = 1; m < month; m++) {
        days = days + daysInMonth(m, year);
    }

    days = days + day;
    return days;
}

void Date::fromDays(long days) {
    year = 1;
    while (true) {
        int daysInYear;
        if (isLeapYear(year)) daysInYear = 366;
        else daysInYear = 365;

        if (days > daysInYear) {
            days = days - daysInYear;
            year++;
        }
        else break;
    }

    month = 1;
    while (true) {
        int daysInMon = daysInMonth(month, year);
        if (days > daysInMon) {
            days = days - daysInMon;
            month++;
        }
        else break;
    }

    day = days;
}

long Date::operator-(const Date& other) const {
    return toDays() - other.toDays();
}

Date Date::operator+(long days) const {
    Date result;
    long totalDays = toDays() + days;
    result.fromDays(totalDays);
    return result;
}

void Date::print() const {
    cout << day << "." << month << "." << year;
}