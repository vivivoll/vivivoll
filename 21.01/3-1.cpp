#include <iostream>
using namespace std;

//Функция создания файла
void act1(char* name)
{
    cout << "Open file..." << name;
}
//Функция удаления файла
void act2(char* name)
{
    cout << "Save file... " << name;
}
//Функция закрытия файла
void act3(char* name)
{
    cout << "Close file... " << name;
}

int main(){
    //Создание и инициализация массива указателей 
    void (*menuActions[3])(char*) = {act1, act2, act3};

    int number;  // Номер выбранного пункта меню.

    char FileName[30];  // Строка для имени файла.

    //Меню пользователя
    cout << "\n 1 - Open";
    cout << "\n 2 - Save";
    cout << "\n 3 - Close";

    //Бесконечный цикл: завершится, когда пользователь введет 3
    while (1)
    {
        while (1)
        {
            /* Цикл продолжается до ввода 
               правильного номера.*/
            cout << "\n\nSelect action: ";
            cin >> number;
            if ((number >= 1) && (number <= 3))
            {
                break;
            }
            else{
                cout << "\nWrong number!";
            }
        }
        if (number != 3)
        {
            cout << "Enter file name: ";
            cin >> FileName;
            (*menuActions[number - 1])(FileName);
        }
        else
        {
            break;
        }
    }
    return 0;
}