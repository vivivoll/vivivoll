#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void InitMatrix(int a[][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            a[i][j] = rand() % 10;
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    int min = a[0][0];
    int max = a[0][0];

    for(int i = 0; i < 5; i++){
        if(a[i][i] < min){
            min = a[i][i];
        }
        if(a[i][i] > max){
            max = a[i][i];
        }
    }
    cout << "Min: " << min << "\n" << "Max: " << max;
    cout << endl;
}


void InitMatrix(double a[][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            a[i][j] = rand() % 10 / 10.0; 
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    double min = a[0][0];
    double max = a[0][0];

    for(int i = 0; i < 5; i++){
        if(a[i][i] < min){
            min = a[i][i];
        }
        if(a[i][i] > max){
            max = a[i][i];
        }
    }
    cout << "Min: " << min << "\n" << "Max: " << max;
    cout << endl;
}

void InitMatrix(char a[][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            a[i][j] = 'A' + rand() % 26; 
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    char min = a[0][0];
    char max = a[0][0];

    for(int i = 0; i < 5; i++){
        if(a[i][i] < min){
            min = a[i][i];
        }
        if(a[i][i] > max){
            max = a[i][i];
        }
    }
    cout << "Min: " << min << "\n" << "Max: " << max;
    cout << endl;
}

int main(){
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    const int row_1 = 5;
    const int col_1 = 5;
    int array_1[row_1][col_1];

    const int row_2 = 5;
    const int col_2 = 5;
    double array_2[row_2][col_2];

    const int row_3 = 5;
    const int col_3 = 5;
    char array_3[row_3][col_3];

    InitMatrix(array_1);
    cout << endl;
    InitMatrix(array_2);
    cout << endl;
    InitMatrix(array_3);
    
    return 0;
}