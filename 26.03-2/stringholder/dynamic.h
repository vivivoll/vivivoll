#pragma once
#include <iostream>
using namespace std;

//Базовый класс
class StringHolder{
protected:
    char* str; //Указатель на динамически выделенную строку

public:
    //Конструктор
    StringHolder(const char* s);

    //Виртуальный деструктор
    virtual ~StringHolder();

    //Виртуальный метод вывода
    virtual void print() const;
};

//Производный класс
class ReverseString : public StringHolder {
public:
    ReverseString(const char* s);

    void print() const override;   //Переопределение метода
};