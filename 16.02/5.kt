fun calculateAverage(vararg numbers: Int): Double{
    var sum = 0
    for(number in numbers){
        sum += number
    }
    return sum.toDouble() / numbers.size
}

fun main(){
    val average = calculateAverage(1, 2, 3)
    val average2 = calculateAverage(10, 20, 30, 40, 50)
    val average3 = calculateAverage(5, 5, 5, 5)

    println(average)
    println(average2)
    println(average3)
}