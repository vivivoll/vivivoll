#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    int x = 10;
    int y = 9;

    int *px; //Разыменование (указание значения)   
    int *py; //Разыменование (указание значения)

    px = &x; //Указание адреса переменной x
    py = &y; //Указание адреса переменной y

    if(*px > *py){
        cout << *px << "> " << *py << endl;
    }                                           //Условие проверки наибольшего
    else{
        cout << *px << "< " << *py << endl;
    }

    return 0;
}