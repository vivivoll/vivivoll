#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <fstream>

using namespace std;

struct Day {
    string date;
    int temp;
};

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-20, 35);

    vector<Day> diary(7);
    time_t now = time(nullptr);

    for (int i = 0; i < 7; ++i) {
        time_t cur = now + i * 24 * 60 * 60;
        tm* ltm = localtime(&cur);
        diary[i].date = to_string(1900 + ltm->tm_year) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday);
        diary[i].temp = dist(gen);
    }

    int sum = 0, min_t = 99, max_t = -99;
    for (const auto& d : diary) {
        sum += d.temp;
        if (d.temp < min_t) min_t = d.temp;
        if (d.temp > max_t) max_t = d.temp;
    }

    cout << "Ср: " << (double)sum / 7 << " Мин: " << min_t << " Макс: " << max_t << "\n";

    for (const auto& d : diary) {
        cout << d.date << ": ";
        for (int j = 0; j < d.temp + 20; ++j) cout << "#";
        cout << " (" << d.temp << ")\n";
    }

    ofstream out("weather.txt");
    for (const auto& d : diary) {
        out << d.date << "," << d.temp << "\n";
    }
    out.close();

    return 0;
}
