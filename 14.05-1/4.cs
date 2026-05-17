using System;

namespace ConsoleNew
{
    class Program
    {
        static void Main(string[] args)
        {
            //Массивы
            int[] firstArray = new int[5] { 1, 2, 3, 4, 5 };
            int[] secondArray = new int[10] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            int[] thirdArray = new int[15];

            //Цикл поиска общих значений
            for (int i = 0; i < firstArray.Length; i++)
            {
                for (int j = 0; j < secondArray.Length; j++)
                {
                    if (firstArray[i] == secondArray[i])
                    {
                        thirdArray[i] = firstArray[i];
                    }
                }
            }

            //Цикл вывода общих
            foreach (int i in thirdArray)
            {
                Console.Write(i + " ");
            }
        }
    }
}
