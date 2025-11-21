#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

template <class T>
void insertSort(T a[], long size)
{
	long i, j;
	T x;

	// цикл проходв, i - номер прохода
	for ( i = 0; i < size; i++)
	{
		x = a[i];
		for (j =  i - 1 ; j>=0 && a[j]>x ; j--)
		{
			// сдвигаем элемент направо, до конца массива
			a[j + 1] = a[j];
		
		}
		//место найдено, вставить элемент
		a[j + 1] = x;
	}
}


int main(){
    setlocale(LC_ALL, "ru");

    srand(time(NULL));
	const long size = 10;
	int ar[size];
	// до сортировки
	for (int i = 0; i < size; i++) {
		ar[i] = rand() % 10;
		cout << ar[i] << "\t";
	}
	cout << "\n\n";
	insertSort(ar, size);
	// после сортировки
		for (int i = 0; i < size; i++) {
			cout << ar[i] << "\t";
		}
	cout << "\n\n";

    return 0;
}