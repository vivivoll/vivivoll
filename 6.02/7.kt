fun main() {
    //Рандомайзер числа от 1 до 100
    val secretNumber = (1..100).random()
    var guess: Int
    var attempts = 0

    //Цикл: работает, пока человек не угадает число
    do {
        print("Введите число: ")
        guess = readLine()!!.toInt()
        attempts++

        //Условие: указывает, больше или меньше заданного числа
        when {
            guess < secretNumber -> println("Больше")
            guess > secretNumber -> println("Меньше")
            else -> {
                println("Вы угадали!")
                println("Количество попыток: $attempts")
            }
        }
    } while (guess != secretNumber)
}
