#include <iostream>
using namespace std;
//Функция для нахождения совершенного числа
bool Perfect(int a){
    int sum = 0;
    for(int i = 1; i < a; i++){
        if(a % i == 0){
            sum += i;
        }
    }
    if(a == sum){
        return true;
    }
    else{
        return false;
    }

}
int main(){
    setlocale(LC_ALL, "ru");
 
    int start = 1;
    int end = 234;   

    for(int i = start; i < end; i++){
        if(Perfect(i) == true){
            cout << i << " ";
        }
    }

    return 0;
}
