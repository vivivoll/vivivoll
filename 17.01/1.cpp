#include <iostream>
using namespace std;

//типизированное пееречисление ошибок
enum ErrorCode {
    SUCCESS,        // 0
    FILE_NOT_FOUND, // 1
    ACCESS_DENIED,  // 2
    OUT_OF_MEMORY   // 3
};

//функция для проверки ошибки
ErrorCode simulateError(int situation) {
    if(situation == 1) return FILE_NOT_FOUND;
    if(situation == 2) return ACCESS_DENIED;
    if(situation == 3) return OUT_OF_MEMORY;
    return SUCCESS;
}

int main() {
    setlocale(LC_ALL, "ru");
    
    //примеры ошибок
    ErrorCode error1 = simulateError(1); 
    ErrorCode error2 = simulateError(0); 
    ErrorCode error3 = simulateError(3); 
    
    //условие проверка на ошибку
    if(error1 == FILE_NOT_FOUND) {
        cout << "Ошибка. Файл не найден" << endl;
    }
    //условие проверка на отсуствие ошибок
    if(error2 == SUCCESS) {
        cout << "Успешно" << endl;
    }
    
    return 0;
}