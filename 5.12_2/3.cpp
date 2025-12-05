#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    const int size = 5;
    int array_1[size] = {1,2,3,4,5};
    int array_2[size] = {6,7,8,9,10};   //Массивы

    int *ptr_1 = array_1;
    int *ptr_2 = array_2;                   //Присваивание адреса
    
    cout << "Вывод массива до действий: " << endl;  //Массив до изменений
    for(int i = 0; i < size; i++){
        cout << *(ptr_1 + i) << " ";
    }

    for(int i = 0; i < size; i++){
        *ptr_1 = *ptr_2;
        ptr_1++;                                //Копирование элементов второго массива в первый  
        ptr_2++;
    }

    int *ptr_start = array_1;
    int *ptr_end = array_1 + size - 1;           //Присваивание адреса: начало массива и конец
    int temp;

    while(ptr_start < ptr_end){
        temp = *ptr_start;
        *ptr_start = *ptr_end;                 //Цикл: пока *ptr_start < *ptr_end, то 1-е число = 5-е число, 5-е число = 1-е число и тд.
        *ptr_end = temp;
        *ptr_start++;
        *ptr_end--;
    }

    cout << "\nМассив после копирования: " << endl; 
    for(int i = 0; i < size; i++){                      //Вывод массива после копирования
        cout << array_1[i] << " ";
    }
    
    return 0;
}