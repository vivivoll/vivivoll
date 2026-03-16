#include <iostream>
#include "buffer.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    Buffer b1(100);
    Buffer b2 = move(b1); //срабатывает оператор присваивания

    return 0;
}