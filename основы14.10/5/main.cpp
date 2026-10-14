#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100);

    vector<int> array(20);
    for (int i = 0; i < 20; ++i) {
        array[i] = dist(gen);
    }

    int target;
    if (!(cin >> target)) return 1;

    vector<int> sorted_asc = array;
    sort(sorted_asc.begin(), sorted_asc.end());

    vector<int> sorted_desc = array;
    sort(sorted_desc.begin(), sorted_desc.end(), greater<int>());

    auto it = find(array.begin(), array.end(), target);
    bool found = (it != array.end());

    long long evens_count = count_if(array.begin(), array.end(), [](int x) { return x % 2 == 0; });

    cout << "Найдено" << (found ? " " : " не ") << "было" << "\n";
    cout << "Четных: " << evens_count << "\n";

    vector<int> large_array(1000);
    for (int i = 0; i < 1000; ++i) {
        large_array[i] = dist(gen);
    }

    auto start = chrono::high_resolution_clock::now();
    sort(large_array.begin(), large_array.end());
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;

    cout << "Время: " << diff.count() << " сек\n";

    return 0;
}
