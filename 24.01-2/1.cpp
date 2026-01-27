#include <iostream>
#include <string>
using namespace std;

// структура комплексного числа
struct ComplexNumber{
    float a;    // вещественная часть
    float b;    // мнимая часть
};

// функция сложения комплексного числа
ComplexNumber add(const ComplexNumber &a1, const ComplexNumber &a2){
    ComplexNumber result;
    result.a = a1.a + a2.a;
    result.b = a1.b + a2.b;
    return result;
}

// функция вычитания комплексного числа
ComplexNumber minus_1(const ComplexNumber &a1, const ComplexNumber &a2){
    ComplexNumber result;
    result.a = a1.a - a2.a;
    result.b = a1.b - a2.b;
    return result;
}

// функция умножения комплексного числа
ComplexNumber mul(const ComplexNumber &a1, const ComplexNumber &a2){
    ComplexNumber result;
    result.a = a1.a * a2.a;
    result.b = a2.b * a2.b;
    return result;
}

// функция деления комплексного числа
ComplexNumber div(const ComplexNumber &a1, const ComplexNumber &a2){
    ComplexNumber result;
    result.a = a1.a / a2.a;
    result.b = a1.b / a2.b;
    return result;
}

// перечисление цветов
enum Color{
    WHITE,  
    RED,    
    GREEN
};

// перечисление типов коробки передач
enum TransmissionType{
    AUTO,   // авто
    MEHANICS  // механика
};

// структура автомобиля
struct Car{
    int lenght;            
    int heught;             
    int volume;             
    int power;             
    int diametr;            
    Color color;           
    TransmissionType transmission;    
};

// функция для задания значений
void SetValue(Car &car){
    cout << "Введите длину: ";
    cin >> car.lenght;

    cout << "Введите высоту посадки: ";
    cin >> car.heught;

    cout << "Введите Объем двигателя: ";
    cin >> car.volume;

    cout << "Введите мощность двигателя: ";
    cin >> car.power;

    cout << "Введите диаметр колес: ";
    cin >> car.diametr;

    cout << "Введите цвет: ";
    string color_string;
    cin >> color_string;
    car.color = stringToColor(color_string);

    cout << "Введите тип коробки передач: ";
    string transmission_string;
    cin >> transmission_string;
    car.transmission = stringToTransmission(transmission_string);
}   

// функция для отображения машины
void ShowCar(Car &car){
    cout << "Длина: " << car.lenght << endl;
    cout << "Высота посадки: " << car.heught << endl;
    cout << "Объем двигателя: " << car.volume << endl;
    cout << "Мощность двигателя: " << car.power << endl;
    cout << "Диаметр колес: " << car.diametr << endl;
    cout << "Цвет: ";
    switch(car.color){
        case WHITE: cout << "Белый"; break;
        case RED: cout << "Красный"; break;
        case GREEN: cout << "Зеленый"; break;
    }
    cout << endl;
    cout << "Тип коробки передач: ";
    switch(car.transmission){
        case AUTO: cout << "Автомат"; break;
        case MEHANICS: cout << "Механика"; break;
    }
    cout << endl;
}

int main(){
    setlocale(LC_ALL, "ru");

    // комплексные числа
    ComplexNumber a1 = {1,1};
    ComplexNumber a2 = {4,4};  

    cout << "КОМПЛЕКСНЫЕ ЧИСЛА" << endl;
    cout << "Первое число: " << a1.a << "," << a1.b << endl;
    cout << "Второе число: " << a2.a << "," << a2.b << endl;
    ComplexNumber sum = add(a1, a2);  // +
    cout << "Сложение. Результат: " << sum.a << " + " << sum.b << "i" << endl;
    ComplexNumber minus_2 = minus_1(a1, a2); // -
    cout << "Вычитание. Результат: " << minus_2.a << " - " << minus_2.b << "i" << endl;
    ComplexNumber multy = mul(a1, a2); // *
    cout << "Умножение. Результат: " << multy.a << " * " << multy.b << "i" << endl;
    ComplexNumber divin = div(a1, a2); // /
    cout << "Деление. Результат: " << divin.a << " / " << divin.b << "i" << endl;

    cout << endl;
    cout << endl;

    Car new_car = {};
    cout << "МАШИНА" << endl;
    // вызов функции для задачи значений автомобиля
    SetValue(new_car);
    cout << "ИНФОРМАЦИЯ О ВВЕДЕННОЙ МАШИНЕ" << endl;
    // вызов функции для отображения значений автомобиля
    ShowCar(new_car);


    return 0;
}