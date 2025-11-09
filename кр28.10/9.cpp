#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int n;
    int max;
    int min;
    cout << "Введите число: ";
    cin >> n;

    int array[n];
    for(int i = 0; i < n; i++){
        array[i] = rand() % 100;
        cout << array[i] << " ";

        if (array[i] > max){
            max = array[i];
        }
        if (array[i] < min){
            min = array[i];
        }
    }
    cout << endl;
    cout << "Минимальное значение: " << min << endl;
    cout << "Максимальное значение: " << max << endl;
    
    return 0;
}
