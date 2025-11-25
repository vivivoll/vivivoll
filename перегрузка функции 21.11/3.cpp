#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    const int size = 10;
    int array[size];        
    int choose;
    int element;
    int new_number;
    double sum = 0;
    int count = 0;

    for(int i = 0; i < size; i++){
        cout << "Введите оценку: " << endl; //Цикл для ввода оценок в массив
        cin >> array[i];
    }

    cout << "Выберите действие:\n1.Вывод оценок\n2.Пересдача экзамена\n3.Выходит ли стипендия\nОтвет:"; //Меню
    cin >> choose;

    switch(choose){
        case 1:
        for(int i = 0; i < size; i++){ //Вывод массива с оценками
            cout << array[i] << "  ";
        }
        break;

        case 2:
        cout << "Введите элемент массива для замены оценки: "; 
        cin >> element;
        cout << "Введите оценку для замены: ";                
        cin >> new_number;

        array[element - 1] = new_number;       //Меняем элемент массива на другую оценку
        
        cout << "Обновленный список оценок:";
        for(int i = 0; i < size; i++){          //Вывод массива с оценками
            cout << array[i] << "  ";
        }
        break;

        case 3:
        for(int i = 0; i < size; i++){ 
            sum += array[i];                    //Цикл для суммирования элементов массива и подсчета кол-ва элеметов
            count += 1;
        }
        double average = sum / count;           //Получаем среднеарифметическое

        if(average >= 10.7){
            cout << "Стипендия есть";
        }                                       //Проверка условий для стипендии
        else{
            cout << "Стипендии нету";
        }
        break;
    }

    return 0;
}