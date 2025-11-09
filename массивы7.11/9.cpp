#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){

    const int a = 10;
    int array[10];
    int average;
    int count = 0;

    for(int i = 0; i < 10; i++){
        array[i] = rand() % 100;
        cout << array[i] << " ";
        count += array[i];
    }
    cout << endl;
    cout << "Average: " << (count) / 10;
    return 0;
}