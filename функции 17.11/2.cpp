#include <iostream>
using namespace std;
//Функция для сложения чисел в определенном диапазоне
int SumNumber(int a, int b){
    int count = 0;
    for(int i = a + 1; i < b; i++){
        count += i;
    }
    return count;
}

int main(){
    setlocale(LC_ALL, "ru");

    int result = SumNumber(1,4);
    cout << "Сумма: " << result;

    return 0;
}
