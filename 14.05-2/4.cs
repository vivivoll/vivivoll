using System;
using System.Reflection.Metadata;

namespace ConsoleNew
{
    class Programs
    {
        static void Main(string[] args)
        {
            //объявление и заполнение двумерного массива
            int [,] myArray = {{1,2,3}, {4,5,6}};

            //ввод выбора стобцов для обмена местами
            Console.Write("Введите первый номер столбца: ");
            string oneString = Console.ReadLine();
            int one = Convert.ToInt32(oneString);

            Console.Write("Введите второй номер столбца: ");
            string twoString = Console.ReadLine();
            int two = Convert.ToInt32(twoString);

            //цикл: смена столбцов выбранные пользователем
            for(int i = 0; i < myArray.GetLength(0); i++)
            {
                int temp = myArray[i,one - 1];
                myArray[i,one - 1] = myArray[i,two - 1];
                myArray[i,two - 1] = temp;
            }

            //цикл: вывод двумерного массива
            for(int i = 0; i < myArray.GetLength(0); i++)
            {
                for(int j = 0; j < myArray.GetLength(1); j++)
                {
                    Console.Write(myArray[i,j] + " ");
                }
                Console.WriteLine();
            }
        }
    }
}