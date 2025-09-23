/*
#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    cout << "первое число: ";
    int a;
    cin >> a;
    cout << "второе число: ";
    int b;
    cin >> b;
    cout << "третье число: ";
    int c;
    cin >> c;
    if (a + b <= c or a + c <= b or b + c <= a)
        cout << "не треугольник" << endl;
    else if (a == b && b == c)
        cout << "равносторонний" << endl;
    else if (a == b or a == c or b == c)
        cout << "равнобедренный" << endl;
    else
        cout << "разносторонний" << endl;
    return 0;
}
*/
/*
#include <iostream>

int main() {
 setlocale(LC_ALL, "ru");
 using namespace std;

 int a, b, c;

 cout << "введите 3 числа\n";
 cin >> a >> b >> c;

 float diskriminant = b ^ 2 - (4 * a * c);
 cout << "дискриминант= " << diskriminant;

 return 0;
}
*/
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int mesaq, number;
    cout << "число месяца(1-12): \n";
    cin >> mesaq;
    cout << "день месяца: \n";
    cin >> number;

    if (mesaq == 12) {
        cout << "зима";
        if (number < 31) {
            cout << "не последний день месяца";
        }
        else {
            cout << "последний день месяца";
        }
    }
    else if (mesaq == 1) {
        cout << "зима";
        if (number < 31) {
            cout << "не последний день месяца";
        }
        else {
            cout << "последний день месяца";
        }
    }
    else if (mesaq == 2) {
        cout << "зима";
        if (number < 28) {
            cout << "не последний день месяца";
        }
        else {
            cout << "последний день месяца";
        }
    }
    else if (mesaq == 3) {
        cout << "весна";
        if (number < 31) {
            cout << "не последний день месяца";
        }
        else {
            cout << "последний день месяца";
        }
    }
    else if (mesaq == 4) {
        cout << "весна";
        if (number < 30) {
            cout << "не последний день месяца";
        }
        else {
            cout << "последний день месяца";
        }
    }
    else if (mesaq == 5) {
        cout << "весна";
        if (number < 31) {
            cout << "не последний день месяца";
        }
        else {
            cout << "последний день месяца";
        }
    }
    else if (mesaq == 6) {
        cout << "лето";
        if (number < 30) {
            cout << "не последний день месяца";
        }
        else {
            cout << "последний день месяца";
        }
    }
    else if (mesaq == 7) {
        cout << "лето";
        if (number < 31) {
            cout << "не последний день месяца";
        }
        else {
            cout << "последний день месяца";
        }
    }
    else if (mesaq == 8) {
        cout << "лето";
        if (number < 31) {
            cout << "не последний день месяца";
        }
        else {
            cout << "последний день месяца";
        }
    }
    else if (mesaq == 9) {
        cout << "осень";
        if (number < 30) {
            cout << "не последний день месяца";
        }
        else {
            cout << "последний день месяца";
        }
    }
    else if (mesaq == 10) {
        cout << "осень";
        if (number < 31) {
            cout << "не последний день месяца";
        }
        else {
            cout << "последний день месяца";
        }
    }
    else if (mesaq == 11) {
        cout << "осень";
        if (number < 30) {
            cout << "не последний день месяца";
        }
        else {
            cout << "последний день месяца";
        }
    }
    else {
        cout << "некорректный номер месяца";
    }

    return 0;
}