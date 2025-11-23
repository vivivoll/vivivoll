#include <iostream>
using namespace std;

int main() {
    for (int row = 0; row < 10; ++row) {          
        for (int col = 0; col < 10; ++col) {      
            cout << char('A' + col) << row << " ";  //Не сам додумал
        }
        cout << endl;
    }

    return 0;
}
