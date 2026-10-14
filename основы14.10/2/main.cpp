#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-30, 30);

    std::vector<int> array(15);
    cout << "Исходный массив: ";
    for (int i = 0; i < 15; ++i) {
        array[i] = dist(gen);
        std::cout << array[i] << " ";
    }
    cout << "\n";

    int sum_positive = 0;
    int count_negative = 0;
    
    for (int x : array) {
        if (x > 0) sum_positive += x;
        if (x < 0) count_negative++;
    }
    
    auto [min_it, max_it] = minmax_element(array.begin(), array.end());

    cout << "Сумма положительных элементов: " << sum_positive << "\n";
    cout << "Количество отрицательных элементов: " << count_negative << "\n";
    cout << "Минимальный элемент: " << *min_it << "\n";
    cout << "Максимальный элемент: " << *max_it << "\n";

    return 0;
}
