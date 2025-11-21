#include <iostream>
using namespace std;

void Square(int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << "*";
        }
        cout << "\n";
    }
}

int main(){

    Square(5,10);
    return 0;
}