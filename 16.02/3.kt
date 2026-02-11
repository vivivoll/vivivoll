fun printPersonInfo(name: String, age: Int = 18, city: String = "Неизвестно"){
    println("Имя: $name, Возраст: $age, Город: $city")
}

fun main(){
    printPersonInfo("Максим", 19, "Чита")
    printPersonInfo("Максим", 19)
    printPersonInfo("Максим")
}