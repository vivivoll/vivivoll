#pragma once

class Kvartira {
private:
    char* address;      //Адрес квартиры
    int floor;          //Этаж
    int people;         //Количество проживающих

public:
    //Конструктор по умолчанию
    Kvartira();

    //Конструктор с параметрами
    Kvartira(const char* adr, int fl = 0, int ppl = 0);

    // Конструктор копирования
    Kvartira(const Kvartira& other);

    // Конструктор перемещения
    Kvartira(Kvartira&& other) noexcept;

    //Деконструктор
    ~Kvartira();

    //Методы
    //Вывод информации
    void Print() const;

    //Геттеры
    const char* getAddress() const;
    int getFloor() const;
    int getPeople() const;

    //Сеттеры
    void setAddress(const char* newAddress);
    void setFloor(int newFloor);
    void setPeople(int newPeople);
};