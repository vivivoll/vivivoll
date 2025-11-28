#include <iostream>
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
			if (a[j - 1] > a[j]) {              //Пузырьковая сортировка
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;

			}
		}
	}
}

template <class T>
void selectionSort(T a[], long size)
{
    for (long i = 0; i < size-1; i++) {
        long minIndex = i;
        for (long j = i+1; j < size; j++) {
            if (a[j] < a[minIndex]) {           //Сортировка выбором
                minIndex = j;
            }
        }
        if (minIndex != i) {
        }
    }
}

int main(){
    setlocale(LC_ALL, "ru");

    const int num_test = 10;
    const int size = 1000;

    for(int i = 0; i < num_test; i++){
                                                //Не понимаю задание
    }

    return 0;
}