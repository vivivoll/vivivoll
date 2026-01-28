#include <iostream>
using namespace std;

//перечисление для битовых флагов отображения
enum DisplayFlags {
    NONE = 0,          //0000
    BORDER = 1 << 0,   //0001 границы
    GRID = 1 << 1,     //0010 сетка
    AXES = 1 << 2,     //0100 оси
    LEGEND = 1 << 3,   //1000 легенда
    ALL = BORDER | GRID | AXES | LEGEND  //1111 все опции
};

//функция для вывода информации о включенных опциях
void ShowDisplayOptions(int flags) {
    cout << "Состояние отображения:\n";

    //проверка отдельных флагов
    if (flags & BORDER) {
        cout << "Границы включены\n";
    }
    else {
        cout << "Границы выключены\n";
    }

    if (flags & GRID) {
        cout << "Сетка включена\n";
    }
    else {
        cout << "Сетка выключена\n";
    }

    if (flags & AXES) {
        cout << "Оси включены\n";
    }
    else {
        cout << "Оси выключены\n";
    }

    if (flags & LEGEND) {
        cout << "Легенда включена\n";
    }
    else {
        cout << "Легенда выключена\n";
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    cout << "Система битовых флагов отображения\n\n";
    
    //пример
    cout << "границы и оси\n";
    int flags1 = BORDER | AXES;
    ShowDisplayOptions(flags1);

    cout << "\nсетка и легенда\n";
    int flags2 = GRID | LEGEND;
    ShowDisplayOptions(flags2);

    cout << "\nвсе включено\n";
    int flags3 = ALL;
    ShowDisplayOptions(flags3);

    cout << "\nдобавление сетки к существующим флагам\n";
    int currentFlags = BORDER | AXES;
    cout << "Было:\n";
    ShowDisplayOptions(currentFlags);

    // Добавляем сетку
    currentFlags |= GRID;
    cout << "\nпосле добавления сетки:\n";
    ShowDisplayOptions(currentFlags);

    cout << "\nудаление осей\n";
    // Удаляем оси
    currentFlags &= ~AXES;
    cout << "после удаления осей:\n";
    ShowDisplayOptions(currentFlags);

    cout << "\nпроверка наличия конкретной опции\n";
    int testFlags = BORDER | LEGEND;
    ShowDisplayOptions(testFlags);

    // Проверка наличия границ
    if (testFlags & BORDER) {
        cout << "\nпроверка границы присутствуют в настройках\n";
    }

    // Проверка отсутствия сетки
    if (!(testFlags & GRID)) {
        cout << "проверка сетка отсутствует в настройках\n";
    }

    return 0;
}