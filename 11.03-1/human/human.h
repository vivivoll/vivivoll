#pragma once

class Human {
private:
    char* FIO;
    int age;

public:
    Human();
    Human(const char* fio, int age = 0);

    // Конструктор копирования
    Human(const Human& other);

    ~Human();

    void Print() const;

    const char* getFIO() const;
    int getAge() const;

    void setFIO(const char* newFIO);
    void setAge(int newAge);
};