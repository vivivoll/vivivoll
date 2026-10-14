#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string text = "мама мыла раму мама";
    stringstream ss(text);
    string word;
    
    map<string, int> counts;
    set<string> unique_words;
    
    while (ss >> word) {
        counts[word]++;
        unique_words.insert(word);
    }

    for (auto const& [w, c] : counts) {
        cout << w << ": " << c << "\n";
    }

    vector<pair<string, int>> vec(counts.begin(), counts.end());
    sort(vec.begin(), vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });

    cout << "Топ слова:\n";
    for (size_t i = 0; i < min(vec.size(), size_t(3)); ++i) {
        cout << vec[i].first << " (" << vec[i].second << ")\n";
    }

    cout << "По алфавиту:\n";
    for (const string& w : unique_words) {
        cout << w << " ";
    }
    cout << "\n";

    return 0;
}
