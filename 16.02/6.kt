fun square(n: Int) = n * n

fun chet(n: Int) = n % 2 == 0

fun max(a: Int, b: Int) = if (a > b) a else b

fun main(){
    println(square(3))
    println(max(1, 2))
    println(max(5, 2))
}
