#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

template <class T>
void shakerSort(T a[], long size) {
    if (size <= 1) return;
    long j, k = size - 1;
    long lb = 1, ub = size - 1;
    T x;
    bool swapped; 
    do {
        swapped = false; 
        
        // проход снизу вверх
        for (j = ub; j > 0; j--) {
            if (a[j - 1] > a[j]) {
                x = a[j - 1];                       //Пузырьковая сортировка
                a[j - 1] = a[j];
                a[j] = x;
                k = j;
                swapped = true;
            }
        }
        lb = k + 1;
        if (!swapped) break; //Доработка: если перестановки небыло (= 0), то прерывается функция
        
        swapped = false;
        for (j = 1; j <= ub; j++) {
            if (a[j - 1] > a[j]) {
                x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
                k = j;
                swapped = true;
            }
        }
        ub = k - 1;
    } while (lb < ub && swapped);
}



int main(){
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    const int size = 10;
    int array[size];                    

    cout << "До сортировки\n";
    for(int i = 0; i < size; i++){      //Цикл для создания массива
        array[i] = rand() % 100;
        cout << array[i] << " ";
    }

    shakerSort(array, size);            //Функция усовершенствованной пузырьковой сортировки

    cout << "\nПосле сортировки\n";
    for(int i = 0; i < size; i++){      //Цикл для вывода отсортированного массива
        cout << array[i] << " ";
    }

    return 0;
}