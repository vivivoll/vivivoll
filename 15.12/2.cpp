#include <iostream>
using namespace std;
// Функция вывода массива В
void InputArray_A(int* array_a, int size) {
    for (int i = 0; i < size; i++) {
        cin >> *(array_a + i);
    }
}
// Функция вывода массива А
void ShowArray_A(int* array_a, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(array_a + i) << " ";
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    // Размеры массивов
    const int size = 3;
    
    //Массив А до действий и new
    int *array_a = new int[size];
    //Массив А после действий и new 
    int *result = new int[size];  
    
    // Ввод массивов
    cout << "Введите элементы массива A: ";
    InputArray_A(array_a, size);
    //Вывод массива А до действий
    cout << "\nИсходный массив A: ";
    ShowArray_A(array_a, size);
    cout << endl;
    //Меню
    int choose;
    cout << "\nМеню:\n";
    cout << "1. Удалить четные\n";
    cout << "2. Удалить нечетные\n";
    cout << "Ваш выбор: ";
    cin >> choose;
    
    //Счетчик
    int count = 0;
    
    //switch case для действий, в зависимости от выбора в меню
    switch (choose) {
    case 1:  //Цикл для удаления нечетных
        for (int i = 0; i < size; i++) {
            if (array_a[i] % 2 != 0) {  
                result[count] = array_a[i];
                count++;
            }
        }
        cout << "Результат: ";
        for (int i = 0; i < count; i++) {
        cout << result[i] << " ";
        }
        cout << endl;
        break;
        
    case 2:  //Цикл для удаления четных
        for (int i = 0; i < size; i++) {
            if (array_a[i] % 2 == 0) { 
                result[count] = array_a[i];
                count++;
            }
        }
        cout << "Результат: ";
        for (int i = 0; i < count; i++) {
        cout << result[i] << " ";
        }
        cout << endl;
        break;
    }
    
    
    
    
    //Освобождение памяти
    delete[] array_a;
    delete[] result;

    return 0;
}