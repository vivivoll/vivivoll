using System;

namespace ConsoleNew
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите предложение на англ: ");
            string str = Console.ReadLine();
            string[] words = str.Split(' '); //Разбивка на слова

            int count = 0; //Счетчик

            foreach (string word in words)
            {
                char[] charArray = word.ToCharArray(); //Преобразование

                //Цикл поиска гласных
                foreach (char i in charArray)
                {
                    if (i == 'e' || i == 'y' || i == 'u' || i == 'i' || i == 'o' || i == 'a')
                    {
                        count++;
                    }
                }
            }
            //Вывод
            Console.WriteLine("Гласных: " + count);
        }
    }
}
