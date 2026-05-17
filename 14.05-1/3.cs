using System;

namespace ConsoleNew
{
    class Program
    {
        static void Main(string[] args)
        {
            //Массив
            int[] array = { 1, 2, 3, 4, 5, 6, 7, 1, 2, 3 };

            //Ввод чисел
            Console.WriteLine("Введите 3 числа");

            Console.Write("1: ");
            string oneStr = Console.ReadLine();
            int one = Convert.ToInt32(oneStr);

            Console.Write("2: ");
            string twoStr = Console.ReadLine();
            int two = Convert.ToInt32(twoStr);

            Console.Write("3: ");
            string threeStr = Console.ReadLine();
            int three = Convert.ToInt32(threeStr);

            //Счетчик
            int count = 0;

            for (int i = 0; i < array.Length; i++)
            {
                if (one == array[i] && two == array[i + 1] && three == array[i + 2])
                {
                    count++;
                }
            }

            Console.WriteLine("Количество повторений " + one + two + three + ": " + count);
        }
    }
}
