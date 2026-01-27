#include <iostream>
using namespace std;

//Функция для добавления строки в конец
int** AddRows(int** matrix, int& rows, int cols){
    
    int** new_matrix = new int*[rows + 1]; //Создание нового массива указателей на + 1

    //Цикл: проходисмся по старому массиву и копируем в новый массив
    for(int i = 0; i < rows; i++){
        new_matrix[i] = matrix[i];
    }

    new_matrix[rows] = new int[cols]; //Создание массива из cols чисел

    for(int j = 0; j < cols; j++){
        new_matrix[rows][j] = 10; //Заполнение новой строки числами
    }

    delete[] matrix; //Удаляем старый массив указателей

    rows = rows + 1; //Кол-во строк на + 1

    return new_matrix; //Возвращаем итоговый массив
}


int main() {
    setlocale(LC_ALL, "ru");
    
    int rows = 3; //Строки
    int cols = 3; //Столбцы

    //Массив указателей на строки
    int** matrix = new int*[rows];

    //Цикл: для каждой строки создаем массив чисел
    for(int i = 0; i < rows; i++){
        matrix[i] = new int[cols];
    }

    //Заполение массива данными
    // 1 строка
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;

    // 2 строка
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;

    // 3 строка
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;

    //Вывод исходного массива
    cout << "Исходный массив" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    matrix = AddRows(matrix, rows, cols); //Вызов функции

    //Вывод готового массива
    cout << "Готовый массив" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    //Цикл: очищаем память
    for(int i = 0; i < rows; i++){
        delete[] matrix[i]; //Удаление каждой строки
    }
    delete[] matrix; //Удаление массива указателей

    return 0;
}