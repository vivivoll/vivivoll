#include <iostream>
using namespace std;

enum pizza {
    pizza1,
    pizza2,
    pizza3,
    pizza4
};

enum drink {
    drink1,
    drink2,
    drink3
};

int main() {
    setlocale(LC_ALL, "ru");

    int pizzaCode, pizza_count;
    int drinkCode, drink_count;


    cout << "Меню:\nПиццы:\n";
    cout << "pizza1 - $8\n";
    cout << "pizza2 - $10\n";
    cout << "pizza3 - $9\n";
    cout << "pizza4 - $11\n";

    cout << "Напитки:\n";
    cout << "drink1 - $1\n";
    cout << "drink2 - $3\n";
    cout << "drink3 - $2\n";


    cout << "Выберите пиццу: ";
    cin >> pizzaCode;
    cout << "Введите количество: ";
    cin >> pizza_count;

 
    cout << "Выберите напиток: ";
    cin >> drinkCode;
    cout << "Введите количество: ";
    cin >> drink_count;


    int pizzaPrice;
    string pizzaName;

    switch (pizzaCode) {
    case pizza1:
        pizzaPrice = 8; 
        pizzaName = "pizza1"; 
        break;

    case pizza2:
        pizzaPrice = 10; 
        pizzaName = "pizza2"; 
        break;

    case pizza3:
        pizzaPrice = 9; 
        pizzaName = "pizza3"; 
        break;

    case pizza4:
        pizzaPrice = 11; 
        pizzaName = "pizza4"; 
        break;
    }



    int drinkPrice;
    string drinkName;

    switch (drinkCode) {
    case drink1:
        drinkPrice = 1; 
        drinkName = "drink1";
        break;

    case drink2:
        drinkPrice = 3; 
        drinkName = "drink2"; 
        break;

    case drink3:
        drinkPrice = 2; 
        drinkName = "drink3"; 
        break;
    }


    int FreePizza = pizza_count / 5;
    int PayPizza = pizza_count - FreePizza;
    int TotalPizza = PayPizza * pizzaPrice;


    int DrinkTotal = drink_count * drinkPrice;
    if (drinkPrice > 2 && drink_count > 3) {
        DrinkTotal = DrinkTotal * 85 / 100;
    }


    
    
    int Total = TotalPizza + DrinkTotal;
    if (Total > 50) {
        Total = Total * 80 / 100;
    }
    
    cout << "Пицца: " << pizzaName << " " << pizza_count << " шт. Цена: " << TotalPizza << "\n";
    cout << "Напитки: " << pizzaName << " " << pizza_count << " шт. Цена: " << DrinkTotal << "\n";
    cout << "Оплата: " << Total;

}