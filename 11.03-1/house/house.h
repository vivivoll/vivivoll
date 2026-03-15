#pragma once

class House {
private:
    char* address;       //Адрес дома
    int kvartira;        //Количество квартир
    int people;          //Общее количество жителей в доме

public:
    //Конструктор по умолчанию
    House();
    //Конструктор с параметрами
    House(const char* adr, int kv = 0, int ppl = 0);

    //Конструктор копирования
    House(const House& other);

    //Конструктор перемещения
    House(House&& other) noexcept;

    //Деконструктор
    ~House();

    //Методы
    //Вывод информации
    void Print() const;

    //Геттеры
    const char* getAddress() const;
    int getKvartira() const;
    int getPeople() const;

    //Сеттеры
    void setAddress(const char* newAddress);
    void setKvartira(int newKvartira);
    void setPeople(int newPeople);
};