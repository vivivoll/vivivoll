#include <iostream>
#include "operator.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    //Массивы с множествами
    int array_a[] = {1,2,3,4,5};
    int array_b[] = {6,7,8,9,10};

    //Объект 
    Mathematics a(array_a, 5);
    Mathematics b(array_b, 5);

    return 0;
}