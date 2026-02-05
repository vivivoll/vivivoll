fun main() {
    print("Введите пароль: ")
    val password = readLine()!!

    //Значения для проверки определенных условий
    var hasDigit = false
    var hasUpper = false
    var hasSpecial = false

    //Специальные символы
    val specialChars = "!@#$%^&*"

    //Цикл: идет до конца пароля
    for (ch in password) {
        //Если в пароле есть цифры, то значение true
        if (ch in '0'..'9') {
            hasDigit = true
        }
        //Если в пароле есть заглавные буквы, то значение true
        if (ch in 'A'..'Z') {
            hasUpper = true
        }
        //Цикл: продолжается до первого символа
        for (s in specialChars) {
            //Если в пароле есть символы, то значение true
            if (ch == s) {
                hasSpecial = true
            }
        }
    }

    //Общее значение для всех проверок
    var isValid = true

    //Условия для вывода определенного невыполненого пункта
    if (password.length < 8) {
        println("Ошибка: пароль должен содержать минимум 8 символов")
        isValid = false
    }
    if (!hasDigit) {
        println("Ошибка: нету цифры")
        isValid = false
    }
    if (!hasUpper) {
        println("Ошибка: нету заглавной буквы")
        isValid = false
    }
    if (!hasSpecial) {
        println("Ошибка: нету специального символа")
        isValid = false
    }

    if (isValid) {
        println("Пароль надёжный!")
    }
}
