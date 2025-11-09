#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){

    const int row = 4;
    const int col = 4;
    int array[row][col];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            array[i][j] = rand() % 101;
            cout << array[i][j] << " ";
        }
        cout << "\n\n";
    }
    int sum = 0;
    for (int j = 0; j < col; j++){
        sum += array[0][j];
    }
    cout << endl;
    cout << "Sum: " << sum;
    return 0;
}