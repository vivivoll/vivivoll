#include <iostream>
using namespace std;

// Смена значений через указатели
void swap(int* a, int* b) {
    if (a != b) {
        *a = *a + *b; 
        *b = *a - *b; 
        *a = *a - *b; 
    }
}


int main() {
    setlocale(LC_ALL, "ru");
    
    // Задача 1
    cout << "ЗАДАЧА 1" << endl;
    int intVar = 10;
    double doubleVar = 5.5;

    // 2 Переменных
    int* intPtr = &intVar;
    double* doublePtr = &doubleVar;

    // Вывод значений
    cout << "Значение int: " << intVar << endl;
    cout << "Адрес int: " << &intVar << endl;
    cout << "Значение указателя int: " << intPtr << endl;
    cout << "Адрес указателя int: " << &intPtr << endl;
    cout << "\n";
    cout << "Значение double: " << doubleVar << endl;
    cout << "Адрес double: " << &doubleVar << endl;
    cout << "Значение указателя double: " << doublePtr << endl;
    cout << "Адрес указателя double: " << &doublePtr << endl;
    
    *intPtr = 20;
    *doublePtr = 12.34;

    cout << "\n";
    cout << "Новое значение int: " << intVar << endl;
    cout << "Новое значение double: " << doubleVar << endl;


    // Задача 2
    cout << "ЗАДАЧА 2" << endl;
    int x = 5;
    int y = 10;

    cout << "До: x = " << x << ", y = " << y << endl;
    swap(&x, &y);
    cout << "После: x = " << x << ", y = " << y << endl;

    // Задача 3
    cout << "ЗАДАЧА 3" << endl;

    int* ptr = new int;

    if (!ptr) {
        cout << "Ошибка памяти" << endl;
        return 1;
    }

    *ptr = 42;
    cout << "Значение: " << *ptr << endl;

    delete ptr;
    ptr = nullptr;

    cout << "Память очищена" << endl;

    // Задача 4
    cout << "ЗАДАЧА 4" << endl;

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    if (n <= 0) {
        cout << "Нужно больше 0" << endl;
        return 1;
    }

    double* arr = new double[n];

    cout << "Введите " << n << " чисел:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    double sum = 0;
    cout << "\nВаш массив: [ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        sum += arr[i]; 
    }
    cout << "]" << endl;

    double average = sum / n;
    cout << "Среднее арифметическое: " << average << endl;

    delete[] arr;
    arr = nullptr;

    // Задача 5
    cout << "ЗАДАЧА 5" << endl;

    int* ptr1 = new int(100);
    int* ptr2 = ptr1;

    delete ptr1;

    ptr1 = nullptr;
    ptr2 = nullptr;

    if (ptr2 != nullptr) {
        cout << "Значение ptr2: " << *ptr2 << endl;
    }
    else {
        cout << "Указатель ptr2 пустой" << endl;
    }



    return 0;
}
