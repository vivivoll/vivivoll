#include <iostream>
using namespace std;

void ShowMatrix(char matr[5][8], int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << matr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
void InitMatrix(char matr[5][8], int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            matr[i][j] = '*';
        }
        cout << endl;
    }
    cout << endl;
}
int main(){
    setlocale(LC_ALL, "ru");
    
    const int iRow = 5;
    const int iCol = 8;
    char iMatr[iRow][iCol];
    InitMatrix(iMatr, iRow, iCol);
    ShowMatrix(iMatr, iRow, iCol);
    return 0;
}