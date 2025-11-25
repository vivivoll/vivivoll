#include <iostream>
using namespace std;

int Nod(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return Nod(b, a % b);
    }
}

int main(){
    setlocale(LC_ALL, "ru");

    cout << Nod(1,7);

    return 0;
}