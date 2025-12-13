#include <iostream>
using namespace std;

// Функция ввода массива А
void InitArray_A(int *array_a, int size){
    for(int i = 0; i < size; i++){
        cin >> *(array_a + i);
    }
}

// Функция ввода массива В
void InitArray_B(int *array_b, int size){
    for(int i = 0; i < size; i++){
        cin >> *(array_b + i);
    }
}

// Функция вывода массива А
void ShowArray_A(int* array_a, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(array_a + i) << " ";
    }
}

// Функция вывода массива В
void ShowArray_B(int* array_b, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(array_b + i) << " ";
    }
}

// Функция вывода массива С
void ShowArray_C(int* array_c, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(array_c + i) << " ";
    }
}

int main(){
    setlocale(LC_ALL, "ru");
    
    // Размеры массивов
    const int size = 3;
    
    // Создание массивов через new
    int *array_a = new int[size];  
    int *array_b = new int[size];  
    int *array_c = new int[size * 2];  
    
    // Указатели массивов 
    int *ptr_a = array_a;
    int *ptr_b = array_b;
    int *ptr_c = array_c;
    
    // Ввод массивов
    cout << "Введите массив A: ";
    InitArray_A(array_a, size);

    cout << "Введите массив B: ";
    InitArray_B(array_b, size);
    
    // Вывод массивов
    cout << "\nМассив A: ";
    ShowArray_A(array_a, size);
    cout << endl;

    cout << "Массив B: ";
    ShowArray_B(array_b, size);
    cout << endl;

    // Начальный индекс массива С
    int index_c = 0;

    // Цикл для добавления из А в С
    for (int i = 0; i < size; i++) {
        array_c[index_c] = array_a[i];
        index_c++;
    }

    // Цикл для добавления из В в С
    for (int i = 0; i < size; i++) {
        array_c[index_c] = array_b[i];
        index_c++;
    }
    
    // Вывод массива С
    cout << "Массив C: ";
    for (int i = 0; i < index_c; i++) {
        cout << array_c[i] << " ";
    }
    cout << endl;

    //Освобождение памяти delete
    delete[] array_a;  
    delete[] array_b;  
    delete[] array_c;  

    return 0;
}