#include <iostream>
using namespace std;

//Функция выбора сортировки по возрастанию
int ascending(int a, int b) {
    return a > b; 
}
//Функция выбора сортировки по убыванию
int descending(int a, int b) {
    return a < b; 
}

//Функция пузырьковой сортировки с компаратором
void bubbleSort(int arr[], int size, int (*comparator)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Используем переданный компаратор
            if (comparator(arr[j], arr[j + 1]) != 0) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    //Указатель на функцию
    int (*comporator)(int, int);
    
    // 4. Массив для сортировки
    int numbers[] = {64, 34, 25, 12};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    int choice;
    
    //Меню пользователя
    cout << "Выберите сортировку" << endl;
    cout << "1.По возрастанию" << endl;
    cout << "2.По убыванию" << endl;
    cout << "Ответ: " << endl;
    cin >> choice;
    
    //Условие выбора способа сортировки
    if (choice == 1) {
        comporator = ascending;
        printf("\nСортировка по возрастанию:\n");
    } else if (choice == 2) {
        comporator = descending;
        printf("\nСортировка по убыванию:\n");
    } else {
        printf("\nНеверный выбор. Используется сортировка по возрастанию.\n");
        comporator = ascending;
    }
    
    cout << "Исходный массив" << endl;
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << "\n";
    
    //Вызов функции для выбранной сортировки
    bubbleSort(numbers, size, comporator);
    
    //Вывод отсортированного массива
    cout << "Результат" << endl;
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << "\n";
    
    return 0;
}