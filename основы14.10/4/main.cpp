#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main() {
    vector<int> grades = {5, 4, 4, 3, 5, 5, 4, 2, 3, 5, 4, 4, 5, 3, 4};
    int n = grades.size();

    double sum = accumulate(grades.begin(), grades.end(), 0.0);
    double mean_val = sum / n;

    sort(grades.begin(), grades.end());
    double median_val;
    if (n % 2 == 0) {
        median_val = (grades[n / 2 - 1] + grades[n / 2]) / 2.0;
    } else {
        median_val = grades[n / 2];
    }

    map<int, int> freq;
    for (int x : grades) {
        freq[x]++;
    }
    int mode_val = grades[0];
    int max_count = 0;
    for (auto const& [val, count] : freq) {
        if (count > max_count) {
            max_count = count;
            mode_val = val;
        }
    }

    double variance_sum = 0.0;
    for (int x : grades) {
        variance_sum += pow(x - mean_val, 2);
    }
    double stdev_val = sqrt(variance_sum / (n - 1));

    cout << "Среднее арифметическое: " << mean_val << "\n";
    cout << "Медиана: " << median_val << "\n";
    cout << "Мода: " << mode_val << "\n";
    cout << "Стандартное отклонение: " << stdev_val << "\n";

    return 0;
}
