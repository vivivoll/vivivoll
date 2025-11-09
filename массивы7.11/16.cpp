#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    srand(time(NULL));
    int array[20];

    for(int i = 0; i < 20; i++){
        array[i] = rand() % 101 - 50;
        cout << array[i] << "  "; 
    }
    cout << endl;
    for(int i = 0; i < 20; i++){
        if (array[i] > 0){
            cout << array[i] << " ";
        }
    }
    return 0;
}