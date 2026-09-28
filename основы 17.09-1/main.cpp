#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double f(double x) {
    return x * x;
}

int main() {
    setlocale(LC_ALL, "Ru");
    //задание 1
    
    double x, y, a;

    cout << "Введите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;

    if (x * y > 0) {
        a = pow(f(x) + y, 2) - sqrt(f(x) * y);
    }
    else if (x * y < 0) {
        a = pow(f(x) + y, 2) + sqrt(abs(f(x) * y));
    }
    else {
        a = pow(f(x) + y, 2) + 1;
    }

    cout << "Ответ = " << a << endl;
    return 0;
    
    //задание 2
    /*
    double x, y, b;

    cout << "Введите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;

    if (y == 0) {
        b = 0;
    }
    else if (x == 0) {
        b = pow(f(x) * f(x) + y, 3);
    }
    else if (x / y > 0) {
        b = log(abs(f(x))) + pow(f(x) * f(x) + y, 3);
    }
    else {
        b = log(abs(f(x) / y)) + pow(f(x) + y, 3);
    }

    cout << "Ответ = " << b << endl;
    return 0;
    */

    //задание 3
    /*
    double x, a, q;

    cout << "Введите x: ";
    cin >> x;
    cout << "Введите a: ";
    cin >> a;

    if (1 < abs(x) && abs(x) < 3) {
        q = ((a * x * x + 2) / (x * x + 1)) * f(x);
    }
    else if (abs(x) >= 3) {
        q = a * a + f(x);
    }
    else {
        q = a * x * f(x) / (x + 2);
    }

    cout << "Ответ = " << q << endl;
    return 0;
    */

    //задание 4
    /*
    double x, b, s;

    cout << "Введите x: ";
    cin >> x;
    cout << "Введите b: ";
    cin >> b;

    if (1 < x * b && x * b < 10) {
        s = exp(f(x));
    }
    else if (12 < x * b && x * b < 40) {
        s = sqrt(abs(f(x) + 4 * b));
    }
    else {
        s = b * f(x) * x * x;
    }

    cout << "Ответ = " << s << endl;
    return 0;
    
    //задание 5

    double x, y, z, m;

    cout << "Введите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;
    cout << "Введите z: ";
    cin >> z;

    m = max({ f(x), y, z }) / min(f(x), y) + 5;

    cout << "Ответ = " << m << endl;

    return 0;
}
*/