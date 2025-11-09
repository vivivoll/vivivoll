#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){

    srand(time(NULL));
    char array[10];

    for(int i = 0; i < 10; i++){
        array[i] = 'A' + rand() % 25;
    }
    cout << array;

    return 0;
}