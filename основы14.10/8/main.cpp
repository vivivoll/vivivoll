#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    string group;
    double grade;
};

int main() {
    ofstream out("students.txt");
    out << "Иванов_И.И. Э-01 4.8\n";
    out << "Петров_П.П. Э-01 4.2\n";
    out << "Сидоров_С.С. М-02 4.6\n";
    out.close();

    ifstream in("students.txt");
    vector<Student> list;
    Student s;
    while (in >> s.name >> s.group >> s.grade) {
        list.push_back(s);
    }
    in.close();

    Student best = list;
    for (const auto& student : list) {
        if (student.grade > best.grade) {
            best = student;
        }
    }

    ofstream filt_out("filtered.txt");
    for (const auto& student : list) {
        if (student.grade > 4.5) {
            filt_out << student.name << " " << student.group << " " << student.grade << "\n";
        }
    }
    filt_out.close();

    cout << "Лучший: " << best.name << " " << best.grade << "\n";

    return 0;
}
