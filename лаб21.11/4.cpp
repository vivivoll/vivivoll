#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

template <typename T>
T MinNumber(T arr[], int size) {
    T min = arr[0];  
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main(){
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    int arr[] = {1, 2, 3, 4, 5};

    cout << "Минимальное: " << MinNumber(arr, 5) << endl;

    return 0;
}
