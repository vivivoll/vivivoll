#include <iostream>
using namespace std;

//типизированное пееречисление дней недели
enum Day {
    MONDAY,    //0
    TUESDAY,   //1
    WEDNESDAY, //2
    THURSDAY,  //3
    FRIDAY,    //4
    SATURDAY,  //5
    SUNDAY     //6
};

//функция для вывода дня недели
string DayName(Day day){
    switch(day){
        case Day::MONDAY:    return "Понедельник";
        case Day::TUESDAY:   return "Вторник";
        case Day::WEDNESDAY: return "Среда";
        case Day::THURSDAY:  return "Четверг";
        case Day::FRIDAY:    return "Пятница";
        case Day::SATURDAY:  return "Суббота";
        case Day::SUNDAY:    return "Воскресенье";
        default:             return "Ошибка!";
    }
}

//функция для проверки выходного дня 
bool Weekend(Day day){
    return(day == Day::SATURDAY || day == Day::SUNDAY);
}

int main(){
    setlocale(LC_ALL, "ru");

    //пример текущего дня
    Day today = SUNDAY;

    //массив всех дней недели
    Day week[] = {
        Day::MONDAY, 
        Day::TUESDAY, 
        Day::WEDNESDAY, 
        Day::THURSDAY, 
        Day::FRIDAY, 
        Day::SATURDAY, 
        Day::SUNDAY
    };

    cout << "---ВСЕ ДНИ НЕДЕЛИ---" << endl;
    //цикл: вывод всех дней недели через функцию Dayname
    for(int i = 0; i < 7; i++){
        Day day = week[i];
        cout << DayName(day) << endl;
    }

    if(Weekend(today)){
        cout << "\nВыходной день";
    }
    else{
        cout << "\nРабочий день";
    }

    return 0;
}