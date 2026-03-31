#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class LinkedList{
private:
    //Структура узла списка
    struct Node {
        T data;     //Хранимое значение
        Node* next; //Указатель на след элемент

        //Конструктор узла
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head; //Указатель на 1-й элемент
    size_t count; //Текущее кол-во в списке
    
public:
    //По умолчанию
    LinkedList() : head(nullptr), count(0) {}

    //Деструктор
    ~LinkedList() {
        clear();
    }

    //Запрет копирования и присваивания
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    //Добавить элемент в начало
    void push_front(const T& value) {
        Node* new_node = new Node(value);
        new_node->next = head;
        head = new_node;
        count++;
    }
    
    //Добавить элемент в конец
    void push_back(const T& value){
        Node* new_node = new Node(value);
        if(head = nullptr){
            head = new_node;
        }   
    }

    //Удалить элемент из начала
    void pop_front(){
        if(head = nullptr){
            return;
        }

    }

    //Удалить элемент из конца
    void pop_back(){
        if(head == nullptr){
            return;
        }
    }

    //Доступ к первому элементу
    T& front(){
        return head->data;
    }

    //Доступ к последнему элементу
    T& back(){

    }

    //Проверка на пустоту
    bool empty() const{
        return head == nullptr;
    }

    //Получение размера
    size_t size() const[
        return count;
    ]

    //Очистка списка
    void clear(){
        delete data;
        count = 0;
    }
};