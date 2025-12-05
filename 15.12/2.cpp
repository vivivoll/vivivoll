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

    //Размер массивов
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

    //Создание временного массива
    int* temp_c = new int[size * 2];
    int c_index = 0;

    //Цикл: добавление элементов из B
    for(int i = 0; i < size; i++){
        if(!isInArray(temp_c, c_index, array_a[i])){
            temp_c[c_index] = array_a[i];
            c_index++;
        }
    }

    //Цикл: добавление элементов из B
    for(int i = 0; i < size; i++){
        if(!isInArray(temp_c, c_index, array_b[i])){
            temp_c[c_index] = array_b[i];
            c_index++;
        }
    }

    //Создание третьего массива
    int* array_c = new int[c_index];
    
    //Ввод элементов для третьего массива
    for(int i = 0; i < c_index; i++){
        array_c[i] = temp_c[i];
    }

    //Вывод третьего массива
    cout << "Массив С: ";
    for(int i = 0; i < c_index; i++){
        cout << array_c[i] << " ";
    }
    cout << endl;

    // Освобождение памяти
    delete[] array_a;
    delete[] array_b;
    delete[] array_c;
    delete[] temp_c;
    
    return 0;
}