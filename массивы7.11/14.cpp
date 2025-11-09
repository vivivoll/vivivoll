#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    const int a = 10;
    int array[10];
    srand(time(NULL));

    for(int i = 0; i < 10; i++){
        array[i] = rand() % 100 + 1;
        cout << array[i] << " ";
    }
    return 0;
}