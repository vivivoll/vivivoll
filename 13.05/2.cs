using System;

namespace ConsoleNew
{
    class Programs
    {
        static bool IsPalindrome(int number)
        {
            //берем абсолютное значение чтобы работало с отрицательными числами
            string s = Math.Abs(number).ToString();
            int left = 0;
            int right = s.Length - 1;

            while (left < right)
            {
                if (s[left] != s[right])
                    return false;
                left++;
                right--;
            }
            return true;
        }

        static void Main(string[] args)
        {
            //Запрос числа у пользователя
            Console.Write("Введите число: ");
            string numberString = Console.ReadLine();
            int number = Convert.ToInt32(numberString);

            //Проверка и вывод результата
            if (IsPalindrome(number))
            {
                Console.WriteLine(number + " - палиндром");
            }
            else
            {
                Console.WriteLine(number + " - не палиндром");
            }
        }
    }
}
