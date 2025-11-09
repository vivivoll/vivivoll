#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    
    srand(time(NULL));
    int array[15];

    for(int i = 0; i < 15; i++){
        array[i] = rand() % 2 - 1;
        cout << array[i] << " ";
    }
    int minus = 0;
    int plus = 14;

    for(int j = 0; j < 15; j++){
        if (array[j] == -1){
            array[minus] = -1;
            minus++; 
        }
        else if (array[j] == 1){
            array[plus] = 1;
            plus--;
        }
    }
    cout << endl;
    cout << "Сортированный список - " << endl;
    for(int i = 0; i < 15; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}