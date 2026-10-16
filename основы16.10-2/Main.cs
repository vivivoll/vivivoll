using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLibrary1
{
    public static class Programm
    {
        public static void Main()
        {
            // ArrayUtils
            int[] numbers = { 5, 3, 8, 3, 1, 5, 2 };
            int min = ArrayUtils.Minimum(numbers); // Минимальное
            int[] sorted = ArrayUtils.SortArray(numbers); // Сортировка
            int[] unique = ArrayUtils.RemoveDuplicates(numbers); // Дубликаты
            Console.WriteLine("Минимум: " + min);
            Console.WriteLine("Сортировка: " + sorted);
            Console.WriteLine("Без дубликатов: " + unique);

            // StringUtils
            Console.WriteLine(); 
            string testString = "тест";
            string reversed = StringUtils.Reverse(testString); // Переворот строки
            int charCount = StringUtils.CountChar(testString, 'и'); // Подсчет буквы
            string replaced = StringUtils.Replace(testString, "тест", "пример"); // Замена строки
            Console.WriteLine("Перевернутая строка: " + reversed);
            Console.WriteLine("Количество букв 'т': " + charCount);
            Console.WriteLine("После замены: " + replaced);

            // MathUtils
            Console.WriteLine();
            int Factorial = 5;
            int num1 = 24; 
            int num2 = 18;
            int Prime = 17;

            long fact = MathUtils.Factorial(Factorial); // Факториал
            int nod = MathUtils.NOD(num1, num2); // НОД
            bool isPrime = MathUtils.IsPrime(Prime); // Проверка на простоту

            Console.WriteLine($"Факториал числа {Factorial}: " + fact);
            Console.WriteLine($"НОД чисел {num1} и {num2}: " + nod);
            Console.WriteLine($"Число {Prime} простое? " + isPrime);
        }


    }
}
