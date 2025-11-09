#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int const row = 3;
    int const col = 3;
    int array[row][col];
    int count = 1;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            array[i][j] = count;
            cout << array[i][j] << " ";
            count ++;
        }
        cout << "\n";
    }
    return 0;
}
