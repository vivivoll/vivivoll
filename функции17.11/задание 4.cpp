#include <iostream>
using namespace std;

int Cube(int number){
    int count = 1;
    for(int i = 0; i < 3; i++){
        count *= number;
    }
    return count;
}
int main(){
    setlocale(LC_ALL, "ru");

    int result = Cube(3);
    cout << "Результат: " << result;

    return 0;
}