#pragma once

class Date {
//Хранение данных
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int y) const; //Проверка на високосный год
    int daysInMonth(int m, int y) const; //Сколько дней в месяце
    long toDays() const; //Переводит дату в дни
    void fromDays(long days); //Переводит дни обратно в дату

public:
    //Параментры по умолчанию 
    Date(int d = 1, int m = 1, int y = 2000);

    long operator-(const Date& other) const; //Разность дат
    Date operator+(long days) const; //Прибавление дней

    void print() const;
};