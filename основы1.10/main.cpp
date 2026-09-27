#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// 1
struct Book {
    string author;
    string title;
    int year;
    double price;
};
// 2
struct Date {
    int day, month, year;
};
struct Employee {
    string name;
    Date hire_date;
};
// 3
struct Student {
    string last_name;
    int course;
    double score;
};
// 6
struct BinStudent {
    char last_name[16];
    int course;
    double score;
};
// 7
struct BinStudent {
    char last_name[16];
    int course;
    double score;
};
// 8
struct Book {
    char author[20];
    char title[30];
    int year;
    bool available;
};

const string FILE_NAME = "library.dat";

void add_book() {
    Book b;
    cout << "Введите автора (до 20 симв.): ";
    cin.ignore();
    cin.getline(b.author, 20);
    cout << "Введите название (до 30 симв.): ";
    cin.getline(b.title, 30);
    cout << "Введите год издания: ";
    cin >> b.year;
    b.available = true; // по умолчанию книга в наличии

    ofstream out(FILE_NAME, ios::binary | ios::app);
    out.write(reinterpret_cast<char*>(&b), sizeof(Book));
    out.close();
    cout << "Книга добавлена в конец файла!\n";
}

void find_book() {
    int n;
    cout << "Введите номер книги для поиска (от 0): ";
    cin >> n;

    ifstream in(FILE_NAME, ios::binary);

    in.seekg(0, ios::end);
    int file_size = in.tellg();
    if (n * sizeof(Book) >= file_size) {
        cout << "Записи с таким номером не существует.\n";
        in.close();
        return;
    }

    Book b;
    in.seekg(n * sizeof(Book));
    in.read(reinterpret_cast<char*>(&b), sizeof(Book));
    in.close();

    cout << "Книга #" << n << ": " << b.author << " — \"" << b.title << "\", " << b.year << " г. ";
    cout << "Статус: " << (b.available ? "В наличии" : "Выдана") << "\n";
}

void change_status() {
    int n;
    cout << "Введите номер книги для изменения статуса (от 0): ";
    cin >> n;

    fstream file(FILE_NAME, ios::in | ios::out | ios::binary);

    file.seekg(0, ios::end);
    int file_size = file.tellg();
    if (n * sizeof(Book) >= file_size) {
        cout << "Записи с таким номером не существует\n";
        file.close();
        return;
    }

    Book b;
    file.seekg(n * sizeof(Book));
    file.read(reinterpret_cast<char*>(&b), sizeof(Book));

    b.available = !b.available;

    file.seekp(n * sizeof(Book));
    file.write(reinterpret_cast<char*>(&b), sizeof(Book));
    file.close();

    cout << "Статус книги успешно изменен на " << (b.available ? "\"В наличии\"" : "\"Выдана\"") << "\n";
}


int main() {
    // 1
    Book myBook = { "Фёдор Достоевский", "Преступление и наказание", 1866, 520.75 };
    cout << "Автор: " << myBook.author << "\n";
    cout << "Название: " << myBook.title << "\n";
    cout << "Год издания: " << myBook.year << "\n";
    cout << "Цена: " << myBook.price << " руб.\n";
    // 2
    vector<Employee> employees = {
        {"Смирнов", {12, 4, 2018}},
        {"Ковалёв", {3, 11, 2022}},
        {"Морозова", {27, 6, 2024}}
    };

    cout << "Сотрудники, принятые после 2020 года:\n";
    for (const auto& emp : employees) {
        if (emp.hire_date.year > 2020) {
            cout << "- " << emp.name << " (Дата приема: "
                << emp.hire_date.day << "."
                << emp.hire_date.month << "."
                << emp.hire_date.year << ")\n";
        }
    }
    // 3
    vector<Student> students = {
        {"Соколов", 1, 4.6},
        {"Волкова", 3, 4.9},
        {"Зайцев", 2, 4.1},
        {"Лебедева", 4, 4.7},
        {"Орлов", 1, 5.0}
    };
    ofstream out("students.txt");
    for (const auto& s : students) {
        out << s.last_name << " " << s.course << " " << s.score << "\n";
    }
    out.close();

    cout << "Файл students.txt успешно создан\n";
    // 4
    ifstream in("students.txt");
    if (!in.is_open()) {
        cout << "Ошибка открытия файла!\n";
        return 1;
    }

    string name, best_student;
    int course, count = 0;
    double score, total_score = 0, max_score = -1;

    while (in >> name >> course >> score) {
        total_score += score;
        count++;

        if (score > max_score) {
            max_score = score;
            best_student = name;
        }
    }
    in.close();

    if (count > 0) {
        cout << "Средний балл всех студентов: " << total_score / count << "\n";
        cout << "Студент с максимальным баллом: " << best_student << " (" << max_score << ")\n";
    }
    else {
        cout << "Файл пуст\n";
    }
    // 5
    ofstream out_all("all_students.txt");
    out_all << "Соколов 1 4.6\nВолкова 3 4.9\nЗайцев 2 4.1\nЛебедева 4 4.7\nОрлов 1 4.4\n";
    out_all.close();

    ifstream fin("all_students.txt");
    ofstream fout("good_students.txt");

    string name;
    int course;
    double score;

    while (fin >> name >> course >> score) {
        if (score >= 4.5) {
            fout << name << " " << course << " " << score << "\n";
        }
    }

    fin.close();
    fout.close();
    cout << "Создан файл good_students.txt.\n";
    // 6
    BinStudent students[5] = {
        {"Sokolov", 1, 4.6},
        {"Volkova", 3, 4.9},
        {"Zaytsev", 2, 4.1},
        {"Lebedeva", 4, 4.7},
        {"Orlov", 1, 5.0}
    };

    ofstream out("students.dat", ios::binary);

    out.write(reinterpret_cast<char*>(students), sizeof(students));
    out.close();

    cout << "Бинарный файл students.dat успешно создан\n";
    // 7
    fstream file("students.dat", ios::in | ios::out | ios::binary);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!\n";
        return 1;
    }

    BinStudent s;

    file.seekg(2 * sizeof(BinStudent));
    file.read(reinterpret_cast<char*>(&s), sizeof(BinStudent));

    cout << "Прочитана 3-я запись: " << s.last_name << ", Курс: " << s.course << ", Балл: " << s.score << "\n";

    s.score = 5.0;

    file.seekp(2 * sizeof(BinStudent));
    file.write(reinterpret_cast<char*>(&s), sizeof(BinStudent));

    file.close();
    cout << "Балл записи изменен на 5.0 и сохранен\n";
    // 8
    int choice;
    while (true) {
        cout << "\nМеню Библиотеки\n";
        cout << "1. Добавить книгу\n";
        cout << "2. Найти книгу по номеру\n";
        cout << "3. Изменить статус наличия\n";
        cout << "4. Выход\n";
        cout << "Выберите операцию: ";
        cin >> choice;

        if (choice == 1) add_book();
        else if (choice == 2) find_book();
        else if (choice == 3) change_status();
        else if (choice == 4) break;
        else cout << "Неверный пункт меню\n";
    }
    return 0;
}