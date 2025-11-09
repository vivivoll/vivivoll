#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int array[8];
    int max = 0;

    for (int i = 0 ; i < 8; i++){
        array[i] = rand() % 100;
        cout << array[i] << " ";

        if (array[i] > max){
            max = array[i];
        }
    }
    cout << endl;
    cout << "Максимальное значение: " << max;

    return 0;
}
