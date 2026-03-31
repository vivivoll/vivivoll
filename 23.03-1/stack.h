#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack{
private:
    T* arr;          //Массив
    size_t capacity;  //Емкость массива
    size_t top;       //Кол-во эл-ов

    //Увеличить размер массива
    void resize(){
        capacity *= 2;
        T* newArr = new T[capacity];
        for (size_t i = 0; i < topIndex; ++i)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }

public:
    //С параметром
    Stack(size_t initCap = 10) : capacity(initCap), topIndex(0) {
        arr = new T[capacity];
    }

    //Деструктор
    ~Stack() {
        delete[] arr;
    }

    //Добавить элемент на вершину
    void push(const T& value){
        if (topIndex == capacity)
            resize();
        arr[topIndex++] = value;
    }

    //Удалить элемент с вершины
    void pop(){
        if (topIndex > 0)
            --topIndex;
    }

    //Доступ к вершине
    T& pop(){
        return arr[topIndex - 1];
    }

    //Проверка на пустоту
    bool empty() const{
        return arr = nullptr;
    }

    //Количество
    size_t size() const{
        return top;
    }
};