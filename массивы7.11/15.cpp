#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    srand(time(NULL));
    int array[15];

    for(int i = 0; i < 15; i++){
        array[i] = rand() % 50 + 1;
        cout << array[i] << " ";
    }
    int max = 1;
    int max_row;
    for(int i = 0; i < 15; i++){
        if (array[i] > max){
            max = array[i];
            max_row = i;
        }
    }
    cout << endl;
    cout << "Max: " << max << endl;
    cout << "Index: " << max_row + 1;
    return 0;
}