#include <iostream>
#include <cmath>
using namespace std;

#define max(a,b) ((a) > (b) ? (a) : (b)) //нахождения макс числа
#define min(a,b) ((a) < (b) ? (a) : (b)) //нахождения мин числа
#define square(a) ((a) * (a)) //возведения числа в квадрат
#define degree(a, b) (pow((a), (b))) //возведения числа в степень
#define parity(a) ((a) % 2 == 0) //проверка числа на четность
#define inparity(a) ((a) % 2 != 0) //проверка числа на нечетность

int main(){
    setlocale(LC_ALL, "ru");

    //для предпроцессора
    int a = 10;
    int b = 5;

    //визуалка
    cout << "Максимальное число: " << max(a,b) << endl;
    cout << "Минимальное число: " << min(a,b) << endl;
    cout << "Число " << a << " в квадрате: " << square(a) << endl;
    cout << "Число " << a << " в " << b << " степени: " << degree(a, b) << endl;
    cout << "Число " << a << ": " << (parity(a) ? "четное" : "нечетное") << endl;
    cout << "Число " << b << ": " << (inparity(b) ? "нечетное" : "четное") << endl;

    return 0;
}