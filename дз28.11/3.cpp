#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

template <class T>
void bubbleSort(T a[], long size)
{
	long i, j;
	T x;
	for ( i = 0; i < size; i++)
	{
		for (j= size - 1 ; j > i; j--)
		{
			if (a[j - 1] > a[j]) {                  //Пузырьковая сортировка
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

    const int size = 10;
    int array[size];
    int k;

    for(int i = 0 ; i < size; i++){
        array[i] = rand() % 10;             //Цикл создания и вывода массива
        cout << array[i] << " ";
    }
    return 0;

    bubbleSort(array,size);                 //Сортировка массива

    for(int i = 0; i < 5; i++){
        cout << array[i] << " ";            //Вывод отсортированной первой половины массива
    }

    for(int i = 5; i < 10; i++){
                                            //Тут не знаю как перевернуть остальную часть массива
    }
}