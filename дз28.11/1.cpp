#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

template <class T>
void bubbleSort(T a[], long size)
{
	long i, j;
	T x;
	for ( i = 0; i < size; i++)                 //Пузырьковая сортировка
	{
		for (j= size - 1 ; j > i; j--)
		{
			if (a[j - 1] > a[j]) {
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
			}
		}
	}
}

int main(){
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    const int size_1 = 5;
    int array_1[size_1];  //Массив мобильных номеров(5шт)
    
    const int size_2 = 5;
    int array_2[size_2];  //Массив домашних номеров(5шт)

    for(int i = 0; i < size_1; i++){
            array_1[i] = rand() % 99999 + 10000;    //Цикл для создания массива с мобильными номерами и их вывода
    }      

    for(int i = 0; i < size_2; i++){
            array_2[i] = rand() % 9999 + 1000;      //Цикл для создания массива с домашними номерами и их вывода
    }
        
    int choose;

    cout << "Меню:\n";
    cout << "1.Сортировка мобильных номеров\n";
    cout << "2.Сортировка домашних номеров\n";          //Меню пользователя
    cout << "3.Вывод пользовательских данных\n";
    cout << "4.Выход\n";
    cout << "Ответ: ";
    cin >> choose;
    
    switch(choose){
        case 1:                                     //case 1: Вывод массива до и после сортировки мобильных номеров
        cout << "До сортировки\n";
        for(int i = 0; i < size_1; i++){
            cout << array_1[i] << " ";              //Цикл вывода массива мобильных номеров
        }

        bubbleSort(array_1, size_1);                //Вызов функции сортировки массива

        cout << "\nПосле сортировки\n";
        for(int i = 0; i < size_1; i++){            //Цикл для вывода отсортированного массива
            cout << array_1[i] << " ";
        }
        break;

        case 2:                                 
        cout << "До сортировки\n";                  //case 2: Вывод массива до и после сортировки домашних номеров
        for(int i = 0; i < size_2; i++){
            cout << array_2[i] << " ";              //Цикл вывода массива домашних номеров
        }
        
        bubbleSort(array_2, size_2);                //Вызов функции сортировки массива

        cout << "\nПосле сортировки\n";
        for(int i = 0; i < size_2; i++){            //Цикл для вывода отсортированного массива
            cout << array_2[i] << " ";
        }
        break;

        case 3:                                     //case 3: Вывод мобильных и домашних номеров
        cout << "Список мобильных номеров\n";
        for(int i = 0; i < size_1; i++){
            cout << array_1[i] << " ";              //Цикл вывода массива мобильных номеров
        }
        cout << "\nСписок домашних номеров\n";
        for(int i = 0; i < size_2; i++){            //Цикл вывода массива домашних номеров
            cout << array_2[i] << " ";
        }
        case 4:                                     //case 4: Выход из программы (break)
        break;
    }
    return 0;
}