#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    if (!getline(cin, s)) return 1;

    cout << "Длина: " << s.length() << "\n";

    string upper_s = s;
    transform(upper_s.begin(), upper_s.end(), upper_s.begin(), ::toupper);
    cout << "Регистр: " << upper_s << "\n";

    size_t pos = s.find("г");
    if (pos != string::npos) cout << "Позиция: " << pos << "\n";
    else cout << "Не найдено\n";

    string replaced_s = s;
    replace(replaced_s.begin(), replaced_s.end(), 'а', '*');
    cout << "Замена: " << replaced_s << "\n";

    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    cout << "Реверс: " << rev_s << "\n";

    return 0;
}
