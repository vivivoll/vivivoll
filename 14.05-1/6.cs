using System;

namespace ConsoleNew
{
    class Program
    {
        static void Main(string[] args)
        {
            //Ввод
            Console.WriteLine("Введите предложение: ");
            string slovo = Console.ReadLine();

            //Счетчик
            int count = 0;

            //Цикл подсчета
            foreach (char i in slovo)
            {
                if (i == ' ')
                {
                    count++;
                }
            }

            //Вывод
            Console.WriteLine("Количество пробелов в предложении: " + count);
        }
    }
}
