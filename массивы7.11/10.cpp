#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){

    srand(time(NULL));
    char array[15];
    for(int i = 0; i < 15; i++){
        int random = rand() % 3;
        array[i] = 'A' + random;
        cout << array[i] << " ";
    }

    int A;
    int B;
    int C;
    
    for(int j = 0; j < 15; j++){
        if (array[j] == 'A'){
            A++;
        }
        else if (array[j] == 'B'){
            B++;
        }
        else if (array[j] == 'C'){
            C++;
        }
    }
    cout << endl;
    cout << "Подсчет" << endl;
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;

    return 0;
}