fun main() {
    val isSunny = true
    val isRainy = false

    println("isSunny && isRainy = ${isSunny && isRainy}")
    println("isSunny || isRainy = ${isSunny || isRainy}")
    println("!isRainy = ${!isRainy}")

    // Комментарий:
    // Первый результат false, потому что оператор && (И) возвращает true
    // только если ОБА операнда true. Здесь isSunny = true, но isRainy = false.
}