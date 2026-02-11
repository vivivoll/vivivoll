import kotlin.math.pow

fun calculateCircleArea(radius: Double): Double {
    return Math.PI * radius.pow(2)
}

fun main(){
    println(calculateCircleArea(5.0))
    println(calculateCircleArea(10.0))
    println(calculateCircleArea(2.5))
}