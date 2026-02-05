fun main(){
    //Ввод числа
    print("Введите число: ")
    val number = readLine()!!.toInt()

    //Выбор системы счисления
    print("Выберите систему счисления\n1.2\n2.8\n3.16\nОтвет: ")
    val choose = readLine()!!.toInt()

    //Условие: проверка выбора системы счисления
    //Двоичная
    if(choose == 1){
        number shl 2
        println("Число в двоичной системе: " + number.toString(2))
    }
    //Восьмиричная
    else if(choose == 2){
        println("Число в восьмиричной системе: " + number.toString(8))
    }
    //Шестнадцатиричная
    else if(choose == 3){
        number shr 16
        println("Число в шестнадцатиричной системе: " + number.toString(16))
    }
}