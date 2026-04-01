#include <iostream>
#include <string>
using namespace std;

//Базовый класс
class Animal{
private:
public:
    virtual void speak() const{
            cout << "I am an animal" << endl;
        }
};

//Производные классы животных
class Dog : public Animal{
private:
public:
    void speak(){
        cout << "Woof" << endl;
    }
};

class Cat : public Animal{
private:
public:
    void speak(){
        cout << "Meow" << endl;
    }
};

class Cow : public Animal{
private:
public:
    void speak(){
        cout << "Moo" << endl;
    }
};

class Horse : public Animal{
private:
public:
void speak(){
    cout << "Neigh" << endl;
}
};

//Метод связывания для вывода звука
void makeSound(const Animal& animal){
    animal.speak();
}


int main(){
    setlocale(LC_ALL, "ru");
    
    //Объявление объектов
    Dog dog;
    Cat cat;
    Cow cow;
    Horse horse;

    //Связывание звуков
    makeSound(dog);
    makeSound(cat);
    makeSound(cow);
    makeSound(horse);

    //Создание объектов
    Animal* animal_1 = new Dog();
    Animal* animal_2 = new Cat();
    Animal* animal_3 = new Cow();
    Animal* animal_4 = new Horse();

    //Вывод звуков
    animal_1->speak();
    animal_2->speak();
    animal_3->speak();
    animal_4->speak();

    //Освобождение памяти
    delete animal_1;
    delete animal_2;
    delete animal_3;
    delete animal_4;

    return 0;
}