#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    int x = 10;
    int y = 5;          //Переменные
    
    int *px;
    int *py;            //Указатели на переменную
    
    px = &x;
    py = &y;            //Разыменование(получения значения)

    cout << x << " " << y << endl;      //Первоначальный результат
    cout << "Меняем местами" << endl;

    int temp = *px;
    *px = *py;                      //Меняем местами значения
    *py = temp;
    
    cout << *px << " " << *py << endl;  //Готовый результат

    return 0;
}