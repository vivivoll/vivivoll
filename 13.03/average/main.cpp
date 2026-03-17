#include <iostream>
#include "avg.h"
using namespace std;


int main(){
    setlocale(LC_ALL, "ru");

    //Массив из чисел
    double array[] = {1,2,3,4,5};

    //Вывод среднего числа
    cout << avg(array,5) << endl;
    
    return 0;
}
