#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <string>
#include "cat.h"
#include <windows.h>

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8); //Через setlocale не получается
    //Объекты
    HouseCat cat("Барсик", 2, "Белый", "Алексей");
    HouseCat cat_3("Мармон", 6, "Бело-рыжий", "Татьяна");
    WildCat cat_1("Лев", 5, "Рыжий", "Африка");
    PersianCat cat_2("Шлёпа", 3, "Черный", 4);
   
    cout << "Информация о кошках" << endl;
    cout << "Домашняя кошка" << endl;
    cat.printInfo();
    cout << endl << endl;
    cout << "Дикая кошка" << endl;
    cat_1.printInfo();
    cout << endl << endl;
    cout << "Персидская кошка" << endl;
    cat_2.printInfo();
    cout << endl << endl;
    cout << "Домашняя кошка" << endl;
    cat_3.printInfo();
    cout << endl << endl;

    return 0;
}