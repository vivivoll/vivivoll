#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int const row = 4;
    int const col = 4;
    int array[row][col];

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            array[i][j] = rand() % 20;
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }

    int total = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            total += array[i][j];
        }
    }

    int max = 0;
    int min = 0;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (array[i][j] > max){
                max = array[i][j];
            }
            if (array[i][j] < min){
                min = array[i][j];
            }
        }
    }



    cout << "Сумма всех чисел = " << total << endl;
    cout << "Средне арифметическое = " << total / (row*col) << endl;
    cout << "Минимальное значение = " << min << endl;
    cout << "Максимальное значение = " << max << endl;
    
    return 0;
}
