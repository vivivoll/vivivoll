#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){

    int a;
    cout << "Введите число - ";
    cin >> a;

    int array[a][a];

    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            array[i][j] = i + j;
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}