#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

template <typename T>
T average(T arr[], T size){
    int sum = 0;

    for(int i = 0; i < size; i++){
        sum += arr[i];
    }

    return sum / size;
}

int main(){
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int arr[] = {1,2,3,4,5};

    cout << "Среднее арифмитическое: " << average(arr, 5);
    
    return 0;
}
