#include <iostream>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int day, month, year;
    if (!(cin >> day >> month >> year)) return 1;

    tm bd_tm = {};
    bd_tm.tm_mday = day;
    bd_tm.tm_mon = month - 1;
    bd_tm.tm_year = year - 1900;
    
    time_t bd_time = mktime(&bd_tm);
    
    string days_ru[] = {"воскресенье", "понедельник", "вторник", "среда", "четверг", "пятница", "суббота"};
    string weekday = days_ru[bd_tm.tm_wday];

    time_t now = time(nullptr);
    tm* today_tm = localtime(&now);

    int age = today_tm->tm_year - bd_tm.tm_year;
    if (today_tm->tm_mon < bd_tm.tm_mon || (today_tm->tm_mon == bd_tm.tm_mon && today_tm->tm_mday < bd_tm.tm_mday)) {
        age--;
    }

    tm next_bd_tm = bd_tm;
    next_bd_tm.tm_year = today_tm->tm_year;
    time_t next_bd_time = mktime(&next_bd_tm);

    if (next_bd_time <= now) {
        next_bd_tm.tm_year = today_tm->tm_year + 1;
        next_bd_time = mktime(&next_bd_tm);
    }

    double diff_seconds = difftime(next_bd_time, now);
    int days_to_bd = ceil(diff_seconds / (60 * 60 * 24));

    cout << "День недели: " << weekday << "\n";
    cout << "Полных лет: " << age << "\n";
    cout << "Дней до следующего ДР: " << days_to_bd << "\n";

    return 0;
}
