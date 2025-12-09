#include <iostream>
using namespace std;
//Функция ввода массива А
void InitArray_A(int *array_a, int size){
    for(int i = 0; i < size; i++){
        cin >> *(array_a + i);
    }
}
//Функция ввода массива В
void InitArray_B(int *array_b, int size){
    for(int i = 0; i < size; i++){
        cin >> *(array_b + i);
    }
}
//Функция вывода массива А
void ShowArray_A(int* array_a, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(array_a + i) << " ";
    }
}
//Функция вывода массива В
void ShowArray_B(int* array_b, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(array_b + i) << " ";
    }
}
//Функция вывода массива С
void ShowArray_C(int* array_c, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(array_c + i) << " ";
    }
}

int main(){
    setlocale(LC_ALL, "ru");
    //Размеры массивов и создание массивов
    const int size = 3;
    int array_a[size];
    int array_b[size];
    int array_c[size];
    //Указатели массивов
    int *ptr_a = array_a;
    int *ptr_b = array_b;
    int *ptr_c = array_c;
    //Ввод массивов
    cout << "Введите массив A: ";
    InitArray_A(array_a, size);

    cout << "Введите массив B: ";
    InitArray_B(array_b, size);
    //Вывод массивов
    cout << "\nМассив A: ";
    ShowArray_A(array_a, size);
    cout << endl;

    cout << "Массив B: ";
    ShowArray_B(array_b, size);
    cout << endl;

    int array_c[100]; // большой массив, чтобы точно хватило
int c_size = 0;

    //Цикл для нахождения элементов массива А, которых нет в В
    for (int i = 0; i < size; i++) {
        bool found = false;
        for (int j = 0; j < size; j++) {
            if (array_a[i] == array_b[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            array_c[c_size] = array_a[i];
            c_size++;
        }
    }

    //Цикл для нахождения элементов массива А, которых нет в В
    for (int i = 0; i < size; i++) {
        bool found = false;
        for (int j = 0; j < size; j++) {
            if (array_b[i] == array_a[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            array_c[c_size] = array_b[i];
            c_size++;
        }
    }

    //Вывод массива С
    cout << "Массив C: ";
    ShowArray_C(array_c, c_size);

    return 0;
}