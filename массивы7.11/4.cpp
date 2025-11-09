#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){

    const int row = 6;
    const int col = 6;
    int array[row][col];

    for(int i = 0; i < row; i++){
        for(int j = i; j < col; j++){
            array[i][j] = rand() % 21;
        }
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < i; j++){
            array[i][j] = array[j][i];
        }
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}