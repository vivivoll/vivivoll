#include <iostream>
#include <memory>
#include <ctime>
using namespace std;

class Timer {
private:
    time_t start;

public:
    //конструктор
    Timer() {
        start = time(NULL);
        cout << "Таймер запущен!" << endl;
    }

    //деструктор
    ~Timer() {
        time_t end = time(NULL);
        int seconds = end - start;
        cout << "Прошло секунд: " << seconds << endl;
        cout << "Таймер уничтожен!" << endl;
    }
};
//возвращает указатель на таймер
unique_ptr<Timer> createTimer() {
    //создаёт объект и возвращает умный указатель
    return make_unique<Timer>();
}

int main() {
    setlocale(LC_ALL, "ru");

    cout << "=== ЗАДАНИЕ 3.1 ===" << endl;
    cout << "Создаём таймер..." << endl;
    //создаём таймер внутри блока {}
    {
        unique_ptr<Timer> timer = createTimer();
        cout << "Таймер работает..." << endl;

        //имитация работы
        cout << "Ждём 3 секунды..." << endl;
        for (int i = 0; i < 300000000; i++);

        cout << "Выходим из блока..." << endl;
    }

    cout << "\nТаймер уже уничтожен за пределами блока!" << endl;
    cout << "Нажмите Enter для выхода...";
    cin.get();

    return 0;
}