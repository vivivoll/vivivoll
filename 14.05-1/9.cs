using System;

namespace ConsoleNew
{
    class Program
    {
        static void Main(string[] args)
        {
            //Ввод
            Console.WriteLine("Введите исходную строку: ");
            string str = Console.ReadLine();

            Console.WriteLine("Введите слово для поиска: ");
            string search = Console.ReadLine();

            //Счетчик
            int count = 0;

            //Цикл поиска схожести
            for (int i = 0; i <= str.Length; i++)
            {
                bool found = true;

                for (int j = 0; j < search.Length; j++)
                {
                    if (str[i + j] != search[j])
                    {
                        found = false;
                        break;
                    }
                }

                //Условие при нахождении
                if (found)
                {
                    count++;
                }
            }

            //Вывод
            Console.WriteLine("Результат поиска: " + count);
        }
    }
}
