#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int sumHuman = 0;
int sumRobot = 0;


int Brosok(){
    return rand() % 6 + 1;
}

int Cube(int n){
    cout << "[" << n << "]";
    return n;
}

int GameHuman(){
    int cube_1 = Brosok();
    int cube_2 = Brosok();
    cout << "Бросок человека: ";
    Cube(cube_1);
    Cube(cube_2);
    cout << "\n";
    sumHuman += cube_1 + cube_2;
    return cube_1 + cube_2;
}

int GameRobot(){
    int cube_1 = Brosok();
    int cube_2 = Brosok();
    cout << "Бросок робота: ";
    Cube(cube_1);
    Cube(cube_2);
    sumRobot += cube_1 + cube_2;
    return cube_1 + cube_2;
}

int main(){
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    int choose;
    cout << "Кто ходит первым:\n1.Человек\n2.Робот\nОтвет: ";
    cin >> choose;

    for(int i = 0; i < 5; i++){
        if(choose == 1){
            GameHuman();
            GameRobot();
        }
        if(choose == 2){
            GameRobot();
            GameHuman();
        }
    }
    cout << "Счет человека: " << sumHuman << endl;
    cout << "Счет робота: " << sumRobot << endl;

    if(sumHuman > sumRobot){
        cout << "Победил человек!" << endl;
        
    }
    else if(sumRobot > sumHuman){
        cout << "Победил робот!" << endl;
    }
    else if(sumHuman == sumRobot){
        cout << "Ничья!" << endl;
    }


    return 0;
}
