fun main() {
    //Ввод строки
    print("Введите строку: ")
    val text = readLine()!!

    //Переменная для результата
    var result = ""

    //Цикл: длится до конца строки
    for (ch in text) {
        //Условие: если символ строки это буква, то сдвиг на 3 символа
        if (ch in 'а'..'я') {
            var newChar = ch + 3
            result += newChar
        }
        //Иначе ничего не меняется
        else {
            result += ch
        }
    }
    //Вывод строки
    println("Зашифрованная строка: $result")
}
