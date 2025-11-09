#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){

    const int row = 3;
    const int col = 3;
    int array[row][col];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            array[i][j] = rand() % 10;
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
    int min = 10;
    int count = 0;
    int min_row = 0;
    int min_col = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if (array[i][j] < min){
                min = array[i][j];
                min_row = i;
                min_col = j;
            }
        }
    }
    cout << endl;
    cout << "Min: " << min << endl;
    cout << "Строка - " << min_row << " Столбец - " << col;
    return 0;
}