fun main() {

    //Меню пользователя
    while (true) {
        println("\nВыберите действие:")
        println("1. Секунды")
        println("2. Часы")
        println("3. Выход")
        print("Ответ: ")
        val choice = readLine()!!.toInt()

        //Условие: выход из программы
        if (choice == 3) {
            println("Выход из программы")
            break
        }

        //Меню с выбранным способом конвертации через when
        when (choice) {
            1 -> {
                print("Введите количество секунд: ")
                val totalSeconds = readLine()!!.toInt()

                //Переменная час
                val hours = totalSeconds / 3600
                //Переменная минута
                val minutes = (totalSeconds % 3600) / 60
                //Переменная секунда
                val seconds = totalSeconds % 60

                println("Результат: $hours:$minutes:$seconds")
            }
            2 -> {
                print("Введите часы: ")
                val hours = readLine()!!.toInt()

                print("Введите минуты: ")
                val minutes = readLine()!!.toInt()

                val totalSeconds = hours * 3600 + minutes * 60
                println("Результат: $totalSeconds секунд")
            }
            else -> {
                println("Неверный пункт меню")
            }
        }
    }
}
