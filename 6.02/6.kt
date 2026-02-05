fun main() {
    val scanner = Scanner(System.`in`)
    
    println("Введите текст (для завершения введите пустую строку):")
    println("----------------------------------------")
    
    // Собираем многострочный текст
    val textLines = mutableListOf<String>()
    while (true) {
        val line = scanner.nextLine()
        if (line.isEmpty()) {
            break
        }
        textLines.add(line)
    }
    
    if (textLines.isEmpty()) {
        println("Текст не был введен.")
        return
    }
    
    // Объединяем все строки в один текст
    val fullText = textLines.joinToString("\n")
    
    // Статистика
    val charCount = fullText.length
    val wordCount = countWords(fullText)
    val sentenceCount = countSentences(fullText)
    val longestWord = findLongestWord(fullText)
    
    // Вывод результатов
    println("\n" + "=".repeat(50))
    println("СТАТИСТИКА ТЕКСТА:")
    println("=".repeat(50))
    println("\nВведенный текст:")
    println("-".repeat(30))
    textLines.forEach { println(it) }
    println("-".repeat(30))
    
    println("\nРезультаты анализа:")
    println("-".repeat(30))
    println("Количество символов: $charCount")
    println("Количество слов: $wordCount")
    println("Количество предложений: $sentenceCount")
    if (longestWord.isNotEmpty()) {
        println("Самое длинное слово: \"$longestWord\" (${longestWord.length} символов)")
    } else {
        println("Самое длинное слово: не найдено")
    }
    println("-".repeat(30))
}

// Функция для подсчета слов
fun countWords(text: String): Int {
    if (text.isBlank()) return 0
    
    // Разделяем текст по пробелам, табуляциям и переносам строк
    val words = text.split(Regex("[\\s\\n\\t]+"))
    
    // Фильтруем пустые строки
    return words.count { it.isNotBlank() }
}

// Функция для подсчета предложений
fun countSentences(text: String): Int {
    if (text.isBlank()) return 0
    
    // Ищем точки, восклицательные и вопросительные знаки
    val sentenceEndings = Regex("[.!?]+")
    
    // Разделяем текст по концам предложений
    val sentences = text.split(sentenceEndings)
    
    // Фильтруем пустые "предложения" (могут появиться из-за нескольких знаков подряд)
    return sentences.count { it.trim().isNotBlank() }
}

// Функция для поиска самого длинного слова
fun findLongestWord(text: String): String {
    if (text.isBlank()) return ""
    
    // Удаляем знаки препинания, кроме дефисов (для составных слов)
    val cleanedText = text.replace(Regex("[^\\p{L}\\p{M}\\s-]"), " ")
    
    // Разделяем на слова
    val words = cleanedText.split(Regex("[\\s\\n\\t]+"))
    
    // Ищем самое длинное слово
    var longestWord = ""
    for (word in words) {
        val cleanWord = word.trim()
        if (cleanWord.isNotBlank() && cleanWord.length > longestWord.length) {
            longestWord = cleanWord
        }
    }
    
    return longestWord
}

// Альтернативная версия с использованием встроенных функций Kotlin
fun analyzeTextAlternative() {
    println("\n" + "=".repeat(50))
    println("АЛЬТЕРНАТИВНАЯ ВЕРСИЯ (однострочный ввод):")
    println("=".repeat(50))
    
    println("Введите текст одной строкой:")
    val text = readlnOrNull() ?: ""
    
    if (text.isBlank()) {
        println("Текст не был введен.")
        return
    }
    
    // Подсчет с использованием функций Kotlin
    val charCount = text.length
    val wordCount = text.split(Regex("\\s+")).count { it.isNotBlank() }
    
    val sentences = text.split(Regex("[.!?]+")).count { it.trim().isNotBlank() }
    
    val longestWord = text.split(Regex("\\W+"))
        .filter { it.isNotBlank() }
        .maxByOrNull { it.length } ?: ""
    
    println("\nРезультаты:")
    println("Количество символов: $charCount")
    println("Количество слов: $wordCount")
    println("Количество предложений: $sentences")
    println("Самое длинное слово: \"$longestWord\" (${longestWord.length} символов)")
}

// Для тестирования можно использовать эту функцию
fun testProgram() {
    println("\n" + "=".repeat(50))
    println("ТЕСТОВЫЙ ПРИМЕР:")
    println("=".repeat(50))
    
    val testText = """
        Привет! Как дела? Это тестовый текст.
        Он содержит несколько предложений и слов.
        Самоедлинноеслововтексте вот такое!
    """.trimIndent()
    
    println("Тестовый текст:")
    println(testText)
    println()
    
    println("Статистика:")
    println("Количество символов: ${testText.length}")
    println("Количество слов: ${countWords(testText)}")
    println("Количество предложений: ${countSentences(testText)}")
    println("Самое длинное слово: \"${findLongestWord(testText)}\"")
}