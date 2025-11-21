#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

template <class T> //Функция пузырьковой сортировки
void bubbleSort(T a[], long size)
{
	long i, j;
	T x;
	for ( i = 0; i < size; i++) //Проходит по всему массиву
	{
		for (j= size - 1 ; j > i; j--) //Перебор чисел справа налево
		{
			if (a[j - 1] > a[j]) { //Если число слева > числа справа
				x = a[j - 1];      
				a[j - 1] = a[j];   //Меняем текущий порядок
				a[j] = x;

			}
		}
	}
}

int main(){
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
	
    const long size = 10;
	
    int ar[size];

	for (int i = 0; i < size; i++) { //Создание массива
		ar[i] = rand() % 10;
		cout << ar[i] << "\t";
	}
	cout << "\n\n";

    bubbleSort(ar, size); //Функция сортировки

	for (int i = 0; i < size; i++) { //Создание отсортированного массива
		cout << ar[i] << "\t";
	}
	cout << "\n\n";
    
    
    
    return 0;
}