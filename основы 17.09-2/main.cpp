#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    // 1
    double x0 = -1.5, xk = 3.5, dx = 0.5;
    double a = -1.25, b = -1.5, c = 0.75;

    for (double x = x0; x <= xk + dx / 2; x += dx) {
        double value = pow(a, 3) * x;

        cout << fixed << setprecision(2) << "x = " << x;

        if (x == 0 || value < 0) {
            cout << ", y = не определено" << endl;
        }
        else {
            double y = (pow(10, -2) * b * c) / x
                     + cos(sqrt(value));

            cout << setprecision(4) << ", y = " << y << endl;
        }
    }
    return 0;
    /*
    // 2
    double x0 = 5.3, xk = 10.3, dx = 0.25;
    double a = 1.35, b = -6.25;

    for (double x = x0; x <= xk + dx / 2; x += dx) {
        double y = a * pow(x, 3)
                 + pow(cos(pow(x, 3) - b), 2);

        cout << fixed << setprecision(2)
             << "x = " << x
             << setprecision(4)
             << ", y = " << y << endl;
    }
    return 0;

    // 3
    double x0 = -0.75, xk = -2.05, dx = -0.2;

    for (double x = x0; x >= xk + dx / 2; x += dx) {
        double y = 9 * pow(x, 4) + sin(57.2 + x);

        cout << fixed << setprecision(2)
             << "x = " << x
             << setprecision(4)
             << ", y = " << y << endl;
    }
    return 0;

    // 4
    double x0 = -0.73, xk = -1.73, dx = -0.1;
    double b = -2;

    for (double x = x0; x >= xk + dx / 2; x += dx) {
        double denominator = pow(
            fabs(pow(b, 3) - pow(x, 3)), 1.5
        );

        cout << fixed << setprecision(2) << "x = " << x;

        if (x == b || denominator == 0) {
            cout << ", y = не определено" << endl;
        }
        else {
            double y = sqrt(fabs(x - b)) / denominator
                     + log(fabs(x - b));

            cout << setprecision(4) << ", y = " << y << endl;
        }
    }
    return 0;

    // 5
    double x0 = 1.23, xk = -2.4, dx = -0.3;
    double b = 12.6;

    for (double x = x0; x >= xk + dx / 2; x += dx) {
        cout << fixed << setprecision(2) << "x = " << x;

        if (fabs(x) < 1e-10) {
            cout << ", y = не определено" << endl;
        }
        else {
            double y = 15.28 * pow(fabs(x), -1.5)
                + cos(log(fabs(x)) + b);

            cout << setprecision(4) << ", y = " << y << endl;
        }
    }
    return 0;
}
*/