#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    const int row = 4;
    const int col = 4;
    int array[row][col];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            array[i][j] = rand() % 10;
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < row; i++) {
        int sum = 0;
        for (int j = 0; j < col; j++) {
            sum += array[i][j];
        }
        cout << "Строка " << i << ": " << sum << endl;
    }

    return 0;
}