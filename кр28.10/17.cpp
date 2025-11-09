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

    int diagonal = 0;
    for (int i = 0; i < row; i++) {
        diagonal += array[i][i]; 
    }
    
    int stroka = 0;
    for (int j = 0; j < col; j++) {
        stroka += array[1][j]; 
    }

    cout << "Сумма диагонали: " << diagonal << endl;
    cout << "Сумма второй строки: " << stroka << endl;

    return 0;
}
