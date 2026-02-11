fun printPersonInfo_1(name: String, age: Int = 18, city: String = "Неизвестно"){
    println("Имя: $name, Возраст: $age, Город: $city")
}

fun main(){
    printPersonInfo_1(city = "Чита", name = "Максим", age = 19)
}