using System;

namespace ConsoleNew
{
    class Program
    {
        static void Main(string[] args)
        {
            //Двумерный массив
            int[,] array = new int[,]
            {
                { 1, 2, 3 },
                { 4, 5, 6 },
                { 7, 8, 9 },
            };

            //Мин и Мах
            int min = 10;
            int max = 0;

            //Цикл для max и min
            foreach (int i in array)
            {
                if (i < min)
                {
                    min = i;
                }
                if (i > max)
                {
                    max = i;
                }
            }

            //Выводы
            Console.WriteLine("Максимальное: " + max);
            Console.WriteLine("Минимальное: " + min);
        }
    }
}
