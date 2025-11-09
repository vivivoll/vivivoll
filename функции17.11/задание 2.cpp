#include <iostream>
using namespace std;

int Factorial(int number){
    int count = 1;
    for(int i = 1; i <= number; i++){
        count *= i;
    }
    return count;
}
int main(){
    setlocale(LC_ALL, "ru");

    int result = Factorial(5);
    cout << "Факториал числа: " << result;
    return 0;
}