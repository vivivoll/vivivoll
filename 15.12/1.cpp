#include <iostream>
using namespace std;

//Функция ввода массива
void InitArray(int *array, int size){
    for(int i = 0; i < size; i++){
        cin >> *(array + i);
    }
}

//Функция вывода массива
void ShowArray(int *array, int size){
    for(int i = 0; i < size; i++){
        cout << *(array + i) << " ";
    }
    cout << endl;
}

//Функция для проверки, есть ли элемент в другом массиве
bool isInArray(int *array, int size, int value){
    for(int i = 0; i < size; i++){
        if(*(array + i) == value){
            return true;
        }
    }
    return false;
}

int main(){
    setlocale(LC_ALL, "ru");

    const int size = 3;
    
    // Выделение памяти
    int* array_a = new int[size];
    int* array_b = new int[size];
    
    //Создание массивов
    int *ptr_a = array_a;
    int *ptr_b = array_b;

    cout << "Введите массив A: ";
    InitArray(array_a, size);
    cout << endl;

    cout << "Введите массив B: ";
    InitArray(array_b, size);
    cout << endl;

    cout << "Массив A: ";
    ShowArray(array_a, size);
    
    cout << "Массив B: ";
    ShowArray(array_b, size);

    // Временный массив
    int* temp_c = new int[size];
    int c_index = 0;

    //Цикл для проверки элемента в другом массиве
    for(int i = 0; i < size; i++){
        bool found_b = false;
        
        for(int j = 0; j < size; j++){
            if(array_a[i] == array_b[j]){
                found_b = true;
                break;
            }
        }
        
        if(!found_b){
            // Проверяем, нет ли уже этого элемента в temp_c
            bool already_in_c = false;
            for(int k = 0; k < c_index; k++){
                if(temp_c[k] == array_a[i]){
                    already_in_c = true;
                    break;
                }
            }
            
            if(!already_in_c){
                temp_c[c_index] = array_a[i];
                c_index++;
            }
        }
    }

    //Третий массив
    int* array_c = new int[c_index];
    
    //Элементы третьего массива
    for(int i = 0; i < c_index; i++){
        array_c[i] = temp_c[i];
    }

    //Вывод третьего массива
    cout << "Массив С: ";
    for(int i = 0; i < c_index; i++){
        cout << array_c[i] << " ";
    }
    cout << endl;

    // Освобоэжение памяти
    delete[] array_a;
    delete[] array_b;
    delete[] array_c;
    delete[] temp_c;
    
    return 0;
}