using System;

namespace ConsoleNew
{
    class Program
    {
        static void Main(string[] args)
        {
            //Массив
            int[] array = { 1, 3, 4, 5, 6, 7, 8, 9, 10 };

            //Ввод значения
            Console.Write("Введите значение: ");
            string numStr = Console.ReadLine();
            int number = Convert.ToInt32(numStr);

            //Счетчик
            int count = 0;

            //Цикл подсчета меньших значений
            for (int i = 0; i < array.Length; i++)
            {
                if (array[i] < number)
                {
                    count++;
                }
            }
            //Вывод
            Console.WriteLine("Количество значений, меньших чем " + number + ": " + count);
        }
    }
}
