#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){

    srand(time(NULL));
    int array[20];

    for(int i = 0; i < 20; i++){
        array[i] = rand() % 50;
        cout << array[i] << " ";
    }
    cout << endl;
    int chet = 0;

    for(int i = 0; i < 20; i++){
        if(array[i] % 2 == 0){
            cout << array[i] << " ";
        }
    }
    return 0;
}