#include <iostream>
using namespace std;

//Функция для удаления строки по указанному номеру
int** DeleteRows(int** matrix, int& rows, int cols, int position) {
    //Условие: позиция должна быть в определенном диапазоне
    if (position < 0 || position >= rows) {
        cout << "Ошибка!" << endl;
        return matrix;
    }
    
    //Новый массив указателей 
    int** new_matrix = new int*[rows - 1];
    
    //Удаляем выбранную строку 
    delete[] matrix[position];
    
    //Цикл копируем строки
    int new_index = 0;
    for (int i = 0; i < rows; i++) {
        //Условие: если текущая строка не совпадает с позицией, то ставим на ее место строку
        if (i != position) {
            new_matrix[new_index] = matrix[i];
            new_index++;
        }
    }
    
    //Удаляем старый массив указателей
    delete[] matrix;
    
    //Уменьшаем количество строк
    rows = rows - 1;
    
    //Возвращаем готовый массив
    return new_matrix;
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

    matrix = DeleteRows(matrix, rows, cols, 1); //Вызов функции

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