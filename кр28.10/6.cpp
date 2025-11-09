#include <iostream>
using namespace std;

int main(){
    setlocale (LC_ALL, "ru");

    int a = 10;
    int b = 10;
    int nok = 1;
        int nod = 1;
    for(int i = 0; i < 10; i++){
        

        if (a / i == b / i && (a / i == b / i) > nod){
            nod++;
        }
        if (a / i == b / i && (a / i == b / i < nok)){
            nok = a / i == b / i;
        }
    }
    cout << "NOD = " << nod << endl; 
    cout << "NOK = " << nok << endl;

    return 0;
}

