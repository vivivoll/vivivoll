#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");
    
    const int size = 5;
    
    int array_1[size] = {1,2,3,4,5};        //Массивы
    int array_2[size] = {6,7,8,9,10};
    
    int *ptr_1 = array_1;
    int *ptr_2 = array_2;                   //Присваивание адреса

    cout << "Массив до копирования: " << endl;
    for(int i = 0; i < size; i++){              //Вывод массива до копирования
        cout << *(ptr_1 + i) << " ";
    }

    for(int i = 0; i < size; i++){
        *ptr_1 = *ptr_2;
        ptr_1++;                                //Копирование элементов второго массива в первый  
        ptr_2++;
    }

    cout << "\nМассив после копирования: " << endl; //Вывод массива после копирования
    for(int i = 0; i < size; i++){
        cout << array_1[i] << " ";
    }




    return 0;
}