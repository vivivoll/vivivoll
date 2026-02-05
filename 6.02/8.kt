fun main() {
    // Создаем матрицу 3x3 и заполняем случайными числами от 1 до 9
    val matrix = Array(3) { IntArray(3) }
    
    println("Матрица 3x3:")
    for (i in 0 until 3) {
        for (j in 0 until 3) {
            matrix[i][j] = Random.nextInt(1, 10)
            print("${matrix[i][j]} ")
        }
        println()
    }
    
    println("\n1. Сумма элементов каждой строки:")
    // Сумма элементов каждой строки
    for (i in 0 until 3) {
        var rowSum = 0
        for (j in 0 until 3) {
            rowSum += matrix[i][j]
        }
        println("Строка ${i + 1}: $rowSum")
    }
    
    println("\n2. Сумма элементов каждого столбца:")
    // Сумма элементов каждого столбца
    for (j in 0 until 3) {
        var colSum = 0
        for (i in 0 until 3) {
            colSum += matrix[i][j]
        }
        println("Столбец ${j + 1}: $colSum")
    }
    
    println("\n3. Сумма элементов главной диагонали:")
    // Сумма элементов главной диагонали
    var diagonalSum = 0
    for (i in 0 until 3) {
        diagonalSum += matrix[i][i]
    }
    println("Сумма = $diagonalSum")
    
    // Альтернативный способ с красивым выводом
    println("\n--- Альтернативный вывод ---")
    println("Матрица:")
    for (i in 0 until 3) {
        print("| ")
        for (j in 0 until 3) {
            print("${matrix[i][j]} ")
        }
        println("|")
    }
    
    println("\nСуммы строк:")
    for (i in 0 until 3) {
        println("Строка ${i + 1}: ${matrix[i].sum()}")
    }
    
    println("\nСуммы столбцов:")
    for (j in 0 until 3) {
        val colSum = (0 until 3).sumOf { i -> matrix[i][j] }
        println("Столбец ${j + 1}: $colSum")
    }
    
    println("\nСумма главной диагонали:")
    val mainDiagonalSum = (0 until 3).sumOf { i -> matrix[i][i] }
    println("Сумма = $mainDiagonalSum")
}