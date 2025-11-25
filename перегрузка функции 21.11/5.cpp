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

    const int size = 10;
    int array[size];
    int sum = 0;
    int average;
    int part;

    for(int i = 0; i < size; i++){
        array[i] = rand() % 10;
        cout << array[i] << " | "; //Цикл для создания массива
        sum += array[i];
    }
    average = sum / size;
    cout << "\nAverage: " << average;

    if(average > 0){
        part = 2 * size / 3;    //Условие проверки массива (>0) Для сортировки 2/3 части массива
        bubbleSort(array, part); //Вызов функции сортировки
    }                                                           
    else{
        part = size / 3;    //Условие проверки массива (>0) Для сортировки 1/3 части массива
        bubbleSort(array, part); //Вызов функции сортировки
    }
    
    int start = part;
    int end = size - 1;
    int temp;

    for(int i = start, j = end; i < j; i++, j--){
        temp = array[i];
        array[i] = array[j];                        //Цикл для обмена местами левого и правого элемента массива (обратный порядок)
        array[j] = temp;
    }

    cout << "\nРезультат: \n";
    for(int i = 0; i < size; i++){ //Вывод отсортированного массива и поменянная местами часть массива
    cout << array[i] << " | ";
    }

    return 0;
}