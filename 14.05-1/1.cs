using System;

namespace ConsoleNew
{
    class Program
    {
        static void Main(string[] args)
        {
            //Массив
            int[] array = { 1, 2, 3, 4, 5, 6, 5, 7, 8, 9, 10 };

            //Цикл вывода четных
            Console.WriteLine("Четные: ");
            for (int i = 0; i < array.Length; i++)
            {
                if (array[i] % 2 == 0)
                {
                    Console.Write(array[i] + " ");
                }
            }
            Console.WriteLine();

            //Цикл вывода нечетных
            Console.WriteLine("Нечетные: ");
            for (int i = 0; i < array.Length; i++)
            {
                if (array[i] % 2 == 1)
                {
                    Console.Write(array[i] + " ");
                }
            }
            Console.WriteLine();

            //Цикл поиска уникальных
            Console.WriteLine("Уникальные");
            for (int i = 0; i < array.Length; i++)
            {
                bool unic = true;

                for (int j = 0; j < array.Length; j++)
                {
                    if (i != j && array[i] == array[j])
                    {
                        unic = false;
                        break;
                    }
                }
                //Вывод уникальных
                if (unic)
                {
                    Console.Write(array[i] + " ");
                }
            }
        }
    }
}
