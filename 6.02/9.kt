fun main() {
    print("Введите N: ")
    val n = readLine()!!.toInt()

    var a = 0
    var b = 1

    //Цикл: продолжается от 1 до введенного числа
    for (i in 1..n) {
        val current = a

        //Условие для числа, которые пропускаем
        if (current % 2 != 0 && !(current > 50 && current < 200)) {
            a = b
            b = current + b
            continue
        }
        //Вывод числа
        println(current)

        //Переход в след числу
        a = b
        b = current + b
    }
}
