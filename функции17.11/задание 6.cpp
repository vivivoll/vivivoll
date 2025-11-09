#include <iostream>
using namespace std;

bool TruthAndLie (int a, int b){
    if (a > b){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    setlocale(LC_ALL, "ru");

    if(TruthAndLie(1,5)){
        cout << "Ложь";
    }
    else{
        cout << "Правда";
    }

    return 0;
}