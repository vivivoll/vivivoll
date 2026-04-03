#include <iostream>
#include <string>
#include <stdexcept>
#include "Logger.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    
    Logger::log(Logger::INFO, "Тестовое информационное сообщение");
    Logger::log(Logger::WARNING, "Предупреждение");
    Logger::log(Logger::ERROR, "Ошибка!");

    {
        using namespace Logger;
        log(INFO, "Сообщение внутри блока");
        FileLogger::logToFile("log.txt", "Сообщение записано в файл");
    }

    return 0;
}