#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

template <class T>
void quickSort(T a[], int left, int right) {
    int i = left;
    int j = right;
    T pivot = a[(left + right) / 2]; //Опорный элемент по центру массива

    while (i <= j) {
        while{
            (a[i] < pivot) i++; //Цикл для нахождения чисел слева (<= pivot)
        }
        while{
            (a[j] > pivot) j--; //Цикл для нахождения чисел Справа (>= pivot)
        }

        if (i <= j) {
            T temp = a[i]; //Условие для расстановки элементов массива слева и справа
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j) quickSort(a, left, j);   //Условие для сортировки массива в левой части от pivot
    if (i < right) quickSort(a, i, right); //Условие для сортировки массива в правой части от pivot
}



int main(){
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    const int size = 10;
    int array[size];

    for (int i = 0; i < size; i++) { //Создание массива
		array[i] = rand() % 10;
		cout << array[i] << "\t";
	}
	cout << "\n\n";

    quickSort(array, 0, size -1); //Вызов функции с сортировкой

    for (int i = 0; i < size; i++) { //Вывод отсортированного массива
		cout << array[i] << "\t";
	}
	cout << "\n\n";

    return 0; 
}


