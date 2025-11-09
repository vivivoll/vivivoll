#include <iostream>
using namespace std;

int main(){
    setlocale (LC_ALL, "ru");
    
    int a;
    cout << "Введите число: ";
    cin >> a;
    
    if (a % 2 == 0){
        cout << "Число четное";
    }
    else {
        cout << "Число нечетное";
    }
    return 0;
    
}

