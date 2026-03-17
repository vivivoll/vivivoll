#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Array{
private:
    int* data;
    int size;
    int capacity; //выделенная память
    int grow; //шаг увеличения  
public:

    //Конструктор по умолчанию
    Array() ;
    //Получения размера массива
    int Getsize() const;

    //Задать размер массива
    int SetSize(int newSize, int newGrow = 1);

    int GetUpperBound() const;

    bool IsEmpty() const;

    int FreeExtra() const;

    int RemoveAll() const;

    int GetAt() const;

    int SetAt() const;

    int Array operator() const;

    int Add() const;

    int Append() const;

    int Array operator=() const;

    int Getdata() const;

    int InsertData() const;

    int RemoveAt() const;

};