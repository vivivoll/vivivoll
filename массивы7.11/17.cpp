#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    srand(time(NULL));
    int array[15];

    for(int i = 0; i < 15; i++){
        array[i] = rand() % 100 - 1;
        cout << array[i] << "  "; 
    }

    for(int i = 0; i < 15; i++){
        if (array[i] < 2){
            continue;
        }
        if (array[i] == 2){
            cout << array[i];
            continue;
        }
        if(array[i] % 3 == 0){
            continue;
        }
    }
    return 0;
}