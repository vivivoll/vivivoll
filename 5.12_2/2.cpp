#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    const int size = 5;
    int array[size] = {1,2,3,4,5};      //Массив

    int *ptr = array;

    cout << "Массив до переворота: " << endl;
    for(int i = 0; i < size; i++){              //Вывод массива до переворота
        cout << *(ptr + i) << " ";
    }

    int *ptr_start = array;
    int *ptr_end = array + size - 1;           //Присваивание адреса: начало массива и конец
    int temp;

    while(ptr_start < ptr_end){
        temp = *ptr_start;
        *ptr_start = *ptr_end;                 //Цикл: пока *ptr_start < *ptr_end, то 1-е число = 5-е число, 5-е число = 1-е число и тд.
        *ptr_end = temp;
        *ptr_start++;
        *ptr_end--;
    }

    cout << "\nМассив после переворота: " << endl;
    for(int i = 0; i < size; i++){                  //Вывод массива после переворота
        cout << array[i] << " ";
    }
    return 0;
}