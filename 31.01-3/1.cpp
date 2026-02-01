#include <iostream>
#include <stdio.h>
#include <cstring>  
#define _CRT_SECURE_NO_WARNINGS //отключение предупреждения
using namespace std;

//структура сотрудника
struct Employee {
    char lastName[30];   //фамилия
    char firstName[30];  //имя
    int age;             //возраст
    char position[30];   //должность
};

//глобальные данные
const int MAX = 10;      //макс. кол. сотрудников
Employee employees[MAX]; //массив сотрудников
int countEmp = 0;        //текущее кол. сотрудников
char fileName[50];       //имя файла с данными сотрудников

//загрузка данных из файла
void loadFromFile() {
    //работа с файлом - открытие
    FILE* f = fopen(fileName, "r");
    //проверка на наличие файла
    if (f == NULL) {
        cout << "Файл не найден" << endl;
        return;
    }
    //цикл работает пока не достигнут конец файла
    while (!feof(f)) {
        //fscanf пытается считать 4 элемента по структуре сотрудника
        if (fscanf(f, "%s %s %d %s",
            employees[countEmp].lastName,
            employees[countEmp].firstName,
            &employees[countEmp].age,
            employees[countEmp].position) == 4) {
            //увеличиваем количество сотрудников
            countEmp++;
        }
    }
    fclose(f);
}

//сохранение данных в файл
void saveToFile() {
    //работа с файлом - перезапись
    FILE* f = fopen(fileName, "w");
    //запись всех сотрудников
    for (int i = 0; i < countEmp; i++) {
        fprintf(f, "%s %s %d %s\n",
            employees[i].lastName,
            employees[i].firstName,
            employees[i].age,
            employees[i].position);
    }
    fclose(f);
}

//добавление нового сотрудника
void addEmployee() {
    //проверка на переполнение массива
    if (countEmp >= MAX) return;
    //ввод данных сотрудника
    cout << "Фамилия: ";
    cin >> employees[countEmp].lastName;
    cout << "Имя: ";
    cin >> employees[countEmp].firstName;
    cout << "Возраст: ";
    cin >> employees[countEmp].age;
    cout << "Должность: ";
    cin >> employees[countEmp].position;
    //увеличиваем счётчик сотрудников
    countEmp++;
}

//редактирования данных сотрудника по фамилии
void editEmployee() {
    char lastName[30];
    cout << "Введите фамилию: ";
    cin >> lastName;
    //идет по кол-ву сотрудников
    for (int i = 0; i < countEmp; i++) {
        //если сотрудник по фамилии найден
        if (strcmp(employees[i].lastName, lastName) == 0) {
            //ввод новых данных
            cout << "Новое имя: ";
            cin >> employees[i].firstName;
            cout << "Новый возраст: ";
            cin >> employees[i].age;
            cout << "Новая должность: ";
            cin >> employees[i].position;
            return;
        }
    }
    //иначе ошибка
    cout << "Сотрудник не найден\n";
}

//удаления сотрудника по фамилии
void deleteEmployee() {
    char lastName[30];
    cout << "Введите фамилию для удаления: ";
    cin >> lastName;
    //идет по кол-ву сотрудников
    for (int i = 0; i < countEmp; i++) {
        //если найден сотрудник по фамилии
        if (strcmp(employees[i].lastName, lastName) == 0) {
            //сдвиг элементов массива влево
            for (int j = i; j < countEmp - 1; j++) {
                employees[j] = employees[j + 1];
            }
            //уменьшаем количество сотрудников
            countEmp--;
            cout << "Сотрудник удалён\n";
            return;
        }
    }
    //иначе ошибка
    cout << "Сотрудник не найден\n";
}


//вывод всех сотрудников
void showAll() {
    //идет по кол-ву сотрудников
    for (int i = 0; i < countEmp; i++) {
        //вывод информации по каждому сотруднику
        cout << i + 1 << ". " << employees[i].lastName << " " << employees[i].firstName << ", " << employees[i].age << ", " << employees[i].position << endl;
    }
}

//поиск сотрудника по фамилии
void findByLastName() {
    char lastName[30];
    cout << "Введите фамилию: ";
    cin >> lastName;
    //работа с файлом - запись
    FILE* f = fopen("result.txt", "w");
    //Цикл: идет по кол-ву сотрудников
    for (int i = 0; i < countEmp; i++) {
        //если найден сотрудник - его вывод
        if (strcmp(employees[i].lastName, lastName) == 0) {
            cout << employees[i].lastName << " "
                << employees[i].firstName << endl;
            //запись в файл информация о сотруднике
            fprintf(f, "%s %s %d %s\n",
                employees[i].lastName,
                employees[i].firstName,
                employees[i].age,
                employees[i].position);
        }
    }
    fclose(f);
}

//поиск сотрудников по возрасту
void findByAge() {
    int age;
    cout << "Введите возраст: ";
    cin >> age;
    //работа с файлом - запись
    FILE* f = fopen("result.txt", "w");
    //идет по кол-ву сотрудников
    for (int i = 0; i < countEmp; i++) {
        //если найден сотрудник, то вывод 
        if (employees[i].age == age) {
            cout << employees[i].lastName << " " << employees[i].firstName << endl;
            //запись в файл информации о сотруднике
            fprintf(f, "%s %s %d %s\n",
                employees[i].lastName,
                employees[i].firstName,
                employees[i].age,
                employees[i].position);
        }
    }
    fclose(f);
}

//поиск сотрудников по первой букве фамилии
void findByLetter() {
    char letter;
    cout << "Введите первую букву фамилии: ";
    cin >> letter;
    //работа с файлом - запись
    FILE* f = fopen("result.txt", "w");
    //идет по кол-ву сотрудников
    for (int i = 0; i < countEmp; i++) {
        //если сотрудник найден, то вывод
        if (employees[i].lastName[0] == letter) {
            cout << employees[i].lastName << " " << employees[i].firstName << endl;
            //запись в файл информации о сотруднике
            fprintf(f, "%s %s %d %s\n",
                employees[i].lastName,
                employees[i].firstName,
                employees[i].age,
                employees[i].position);
        }
    }
    fclose(f);
}


//вывода меню программы
void menu() {
    cout << "\n1. Добавить сотрудника";
    cout << "\n2. Редактировать сотрудника";
    cout << "\n3. Удалить сотрудника";
    cout << "\n4. Показать всех";
    cout << "\n5. Поиск по фамилии";
    cout << "\n6. Поиск по возрасту";
    cout << "\n7. Поиск по первой букве фамилии";
    cout << "\n8. Сохранить в файл";
    cout << "\n0. Выход\n";
}

int main() {
    setlocale(LC_ALL, "ru");

    //ввод имени файла
    cout << "Введите имя файла: ";
    cin >> fileName;

    //загрузка данных из файла
    loadFromFile();

    //переменная для выбора
    int choice;

    //меню работает до тех пор пока пользователь не введет 0 (Выход)
    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1: addEmployee(); break;
        case 2: editEmployee(); break;
        case 3: deleteEmployee(); break;
        case 4: showAll(); break;
        case 5: findByLastName(); break;
        case 6: findByAge(); break;
        case 7: findByLetter(); break;
        case 8: saveToFile(); break;
        }
    } while (choice != 0);

    //сохранение
    saveToFile();
    cout << "Данные сохранены. Выход.\n";

    return 0;
}
