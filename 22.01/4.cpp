//1
/*
#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    int numbers[10];    //Одномерный массив

    cout << "10 number = ";
    for(int i = 1; i < 10; i++){    //Цикл: ввод 10 чисел, пока i < 10
        cin >> numbers[i];
    }

    int min = numbers[0];           //Переменная для минимума

    for(int i = 1; i < 10; i++){    //Цикл работает, пока i < 10
        if(numbers[i] < min){       //Условие: если перебираемое число < минимального числа, то оно становится минимальным числом
            min = numbers[i];
        }
    }

    cout << "Min = " << min;        //Вывод результата

    return 0;
}
*/
//2
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},              //Матрица
        {7, 8, 9}
    };

    cout << "Matrix:\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {         //Цикл внутри цикла: вывод матрицы
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {         //Цикл внутри цикла: сложение матрицы
            sum += matrix[i][j];
        }
        cout << "Sum = " << sum << "\n";    //Вывод результата
    }

    return 0;
}