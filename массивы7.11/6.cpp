#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    const int row = 5;
    const int col = 5;
    int array[row][col];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            array[i][j] = rand() % 100;
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}