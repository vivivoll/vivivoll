#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

// 1
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    set<int> seen;
    set<int> duplicates;

    for (int num : nums) {
        if (seen.count(num)) {
            duplicates.insert(num);
        } else {
            seen.insert(num);
        }
    }

    cout << "Количество уникальных значений: " << seen.size() << endl;

    cout << "Повторяются более одного раза: ";
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;
/*
// 2
    set<int> ani = {10, 20, 30, 40};
    set<int> bori = {30, 40, 50, 60};

    set<int> common;
    set<int> only_ani;
    set<int> all_friends = bori;


    for (int id : ani) {
        if (bori.count(id)) {
            common.insert(id);
        } else {
            only_ani.insert(id);
        }
        all_friends.insert(id);
    }

    cout << "Общие друзья: ";
    for (int id : common) cout << id << " ";
    cout << endl;

    cout << "Только у первого (Ани): ";
    for (int id : only_ani) cout << id << " ";
    cout << endl;

    cout << "Всего знакомых: ";
    for (int id : all_friends) cout << id << " ";
    cout << endl;


// 3
bool isAnagram(string word1, string word2) {
    if (word1.length() != word2.length()) return false;
    
    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());
    
    return word1 == word2;
}

// 4
    set<string> math = {"Иванов", "Петров", "Сидоров", "Кузнецов"};
    set<string> phys = {"Петров", "Сидоров", "Смирнов"};
    set<string> info = {"Сидоров", "Кузнецов", "Смирнов", "Волков"};

    map<string, int> student_counts;
    
    for (string s : math) student_counts[s]++;
    for (string s : phys) student_counts[s]++;
    for (string s : info) student_counts[s]++;
    
    cout << "1. Отличники по всем трем предметам: ";
    for (auto const& [name, count] : student_counts) {
        if (count == 3) cout << name << " ";
    }
    cout << endl;
    
    cout << "2. Отличники хотя бы по одному предмету: ";
    for (auto const& [name, count] : student_counts) {
        cout << name << " ";
    }
    cout << endl;
    
    cout << "3. Отличники ровно по двум предметам: ";
    for (auto const& [name, count] : student_counts) {
        if (count == 2) cout << name << " ";
    }
    cout << endl;
    
    cout << "4. Отличники только по математике: ";
    for (string s : math) {
        if (phys.count(s) == 0 && info.count(s) == 0) {
            cout << s << " ";
        }
    }
    cout << endl;


    // 5
    vector<string> p1 = {"мама", "мыла", "раму"};
    vector<string> p2 = {"папа", "мыла", "раму"};
    
    set<string> set1(p1.begin(), p1.end());
    set<string> set2(p2.begin(), p2.end());
    
    map<string, int> all_words;
    for (string w : p1) all_words[w]++;
    for (string w : p2) all_words[w]++;

    cout << "Все уникальные слова в тексте: ";
    for (auto const& [word, count] : all_words) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Слова, встречающиеся более одного раза: ";
    for (auto const& [word, count] : all_words) {
        if (count > 1) cout << word << " ";
    }
    cout << endl;
    
    cout << "Есть в 1-м абзаце, но нет во 2-м: ";
    for (string w : set1) {
        if (set2.count(w) == 0) {
            cout << w << " ";
        }
    }
    cout << endl;
    return 0;
}
// 6
id analyzeNumber(long long N) {
    string s = to_string(N);
    map<char, int> digit_counts;

    for (char c : s) {
        digit_counts[c]++;
    }

    cout << "1. Количество различных цифр: " << digit_counts.size() << endl;

    cout << "2. Цифры, встречающиеся ровно один раз: ";
    bool has_once = false;
    for (auto const& [digit, count] : digit_counts) {
        if (count == 1) {
            cout << digit << " ";
            has_once = true;
        }
    }
    if (!has_once) cout << "нет";
    cout << endl;

    cout << "3. Панцифровое число: ";
    if (digit_counts.size() == 10) {
        cout << "да" << endl;
    }
    else {
        cout << "нет" << endl;
    }
}
*/