#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    double a = 4;
    double b = 9;
    double c = -16;

    double mean_arithmetic = (a + b + c) / 3.0;
    double mean_geometric = std::pow(std::abs(a * b * c), 1.0 / 3.0);
    double max_abs = std::max({std::abs(a), std::abs(b), std::abs(c)});

    cout << "среднее арифм. = " << mean_arithmetic << "\n";
    cout << "среднее геом. = " << mean_geometric << "\n";
    cout << "макс. по модулю = " << max_abs << "\n";

    return 0;
}
