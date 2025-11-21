#include <iostream>
using namespace std;

bool Simple(int a) {
    if (a <= 1){
        return false;
    } 
    for (int i = 2; i < a; i++){
        if (a % i == 0){
            return false; 
        }
    }
    return true; 
}

int main(){
    setlocale(LC_ALL, "ru");

    if(Simple(6)){
        cout << "Простое";
    }
    else{
        cout << "Непростое";
    }
    return 0;
}