#include <iostream>
using namespace std;

//Функция для возведения числа в конкретную степень
int Degree(int a, int b){
    int result = 1;
    for(int i = 0; i < b; i++){
        result *= a;
    }
    return result;
}

int main(){
    setlocale(LC_ALL, "ru");

    int result = Degree(5,5);
    cout << "Результат: " << result;

    return 0;
}
