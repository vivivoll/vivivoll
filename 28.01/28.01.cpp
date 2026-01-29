#include <iostream>
#include <cmath>
#include <string>

using namespace std;
//1
struct Rectangle {
    double x, y;      //координаты верхнего левого угла
    double width;     //ширина
    double height;    //высотп
};

//функция перемещения прямоугольника
void moveRectangle(Rectangle& rect, double dx, double dy) {
    rect.x += dx;
    rect.y += dy;
}

//функция изменения размера прямоугольника
void resizeRectangle(Rectangle& rect, double newWidth, double newHeight) {
    rect.width = newWidth;
    rect.height = newHeight;
}

//функция печати информации о прямоугольнике
void printRectangle(const Rectangle& rect) {
    cout << "Прямоугольник:" << endl;
    cout << " Верхний левый угол: (" << rect.x << ", " << rect.y << ")" << endl;
    cout << " Ширина: " << rect.width << endl;
    cout << " Высота: " << rect.height << endl;
    cout << " Площадь: " << rect.width * rect.height << endl;
    cout << " Периметр: " << 2 * (rect.width + rect.height) << endl;
    cout << " Правый нижний угол: (" << rect.x + rect.width << ", " << rect.y - rect.height << ")" << endl;
}
//2
struct Point {
    double x, y;
};

//функция вычисления расстояния между двумя точками
double distanceBetweenPoints(const Point& p1, const Point& p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}
//3
struct Fraction {
    int numerator;    //ччислитель
    int denominator;  //знаменатель

    //конструктор для простого создания дробей
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denom == 0) {
            cout << "Ошибка. Знаменатель не может быть равен 0" << endl;
            denominator = 1;
        }
        reduce(); //автоматически сокращаем дробь при создании
    }

    //функция для нахождения НОД
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return abs(a);
    }

    //функция сокращения дроби
    void reduce() {
        int divisor = gcd(numerator, denominator);
        if (divisor != 0) {
            numerator /= divisor;
            denominator /= divisor;
        }

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    //перевод неправильной дроби в смешанное число
    string toMixedNumber() const {
        if (denominator == 0) return "Неопределено";

        if (abs(numerator) < denominator) {
            return to_string(numerator) + "/" + to_string(denominator);
        }
        else {
            int whole = numerator / denominator;
            int remainder = abs(numerator) % denominator;
            if (remainder == 0) {
                return to_string(whole);
            }
            else {
                return to_string(whole) + " " + to_string(remainder) + "/" + to_string(denominator);
            }
        }
    }

    //печать дроби в разных форматах
    void print() const {
        cout << numerator << "/" << denominator;
    }

    void printMixed() const {
        cout << toMixedNumber();
    }
};

//перегрузка операторов для работы с дробями
Fraction operator+(const Fraction& f1, const Fraction& f2) {
    int num = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    int denom = f1.denominator * f2.denominator;
    Fraction result(num, denom);
    result.reduce();
    return result;
}

Fraction operator-(const Fraction& f1, const Fraction& f2) {
    int num = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    int denom = f1.denominator * f2.denominator;
    Fraction result(num, denom);
    result.reduce();
    return result;
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    int num = f1.numerator * f2.numerator;
    int denom = f1.denominator * f2.denominator;
    Fraction result(num, denom);
    result.reduce();
    return result;
}

Fraction operator/(const Fraction& f1, const Fraction& f2) {
    if (f2.numerator == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        return Fraction(0, 1);
    }
    int num = f1.numerator * f2.denominator;
    int denom = f1.denominator * f2.numerator;
    Fraction result(num, denom);
    result.reduce();
    return result;
}

//основная программа
int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Задание 1. Прямоугольник" << endl;
    Rectangle rect = { 0, 0, 5, 3 };
    printRectangle(rect);

    cout << "\nПосле перемещения на (2, -1):" << endl;
    moveRectangle(rect, 2, -1);
    printRectangle(rect);

    cout << "\nПосле изменения размера (ширина = 7, высота = 4):" << endl;
    resizeRectangle(rect, 7, 4);
    printRectangle(rect);

    cout << "\nЗадание 2. Расстояние между точками" << endl;
    Point p1 = { 0, 0 };
    Point p2 = { 3, 4 };

    cout << "Точка 1: (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "Точка 2: (" << p2.x << ", " << p2.y << ")" << endl;
    cout << "Расстояние между точками: " << distanceBetweenPoints(p1, p2) << endl;

    cout << "\nЗадание 3. Операции с дробями" << endl;

    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(5, 3);  //неправильная дробь
    Fraction f4(6, 8);  //дробь, которую нужно сократить

    cout << "Дробь 1: "; f1.print();
    cout << " (смешанное число: "; f1.printMixed(); cout << ")" << endl;

    cout << "Дробь 2: "; f2.print();
    cout << " (смешанное число: "; f2.printMixed(); cout << ")" << endl;

    cout << "Дробь 3: "; f3.print();
    cout << " (смешанное число: "; f3.printMixed(); cout << ")" << endl;

    cout << "Дробь 4: "; f4.print();
    cout << " (сокращенная: "; f4.print(); cout << ")" << endl;

    // +
    Fraction sum = f1 + f2;
    cout << "\n" << f1.numerator << "/" << f1.denominator << " + "
        << f2.numerator << "/" << f2.denominator << " = ";
    sum.print();
    cout << " (смешанное число: "; sum.printMixed(); cout << ")" << endl;

    // -
    Fraction diff = f2 - f1;
    cout << f2.numerator << "/" << f2.denominator << " - "
        << f1.numerator << "/" << f1.denominator << " = ";
    diff.print();
    cout << " (смешанное число: "; diff.printMixed(); cout << ")" << endl;

    // *
    Fraction product = f1 * f2;
    cout << f1.numerator << "/" << f1.denominator << " * "
        << f2.numerator << "/" << f2.denominator << " = ";
    product.print();
    cout << " (смешанное число: "; product.printMixed(); cout << ")" << endl;

    // :
    Fraction quotient = f2 / f1;
    cout << f2.numerator << "/" << f2.denominator << " / "
        << f1.numerator << "/" << f1.denominator << " = ";
    quotient.print();
    cout << " (смешанное число: "; quotient.printMixed(); cout << ")" << endl;

    //работа с неправильными дробями
    cout << "\n--- Работа с неправильными дробями ---" << endl;
    Fraction f5(7, 3);
    Fraction f6(5, 2);

    cout << "Дробь 5: "; f5.print();
    cout << " (смешанное число: "; f5.printMixed(); cout << ")" << endl;

    cout << "Дробь 6: "; f6.print();
    cout << " (смешанное число: "; f6.printMixed(); cout << ")" << endl;

    Fraction sum2 = f5 + f6;
    cout << "Сумма: "; f5.print(); cout << " + "; f6.print(); cout << " = ";
    sum2.print();
    cout << " (смешанное число: "; sum2.printMixed(); cout << ")" << endl;

    return 0;
}