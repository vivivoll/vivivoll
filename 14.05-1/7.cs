using System;

namespace ConsoleNew
{
    class Program
    {
        static void Main(string[] args)
        {
            string text = "i like C#";
            string[] words = text.Split(' '); //Разбивка на слова

            foreach (string i in words)
            {
                char[] charArray = i.ToCharArray(); //Преобразование с charArray
                Array.Reverse(charArray); //Переворот
                string reversedWord = new string(charArray); //Новая строка
                Console.Write(reversedWord + " "); //Вывод
            }
        }
    }
}
