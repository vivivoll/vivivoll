using System;

namespace ConsoleNew
{
    class Programs
    {
        static void DrawSquare(int size, char symbol)
        {
            for (int row = 0; row < size; row++)
            {
                for (int col = 0; col < size; col++)
                {
                    Console.Write(symbol);
                }
                Console.WriteLine();
            }
        }

        static void Main(string[] args)
        {
            //Запрос размера стороны квадрата
            Console.Write("Введите длину стороны квадрата: ");
            string sizeString = Console.ReadLine();
            int size = Convert.ToInt32(sizeString);

            //Запрос символа
            Console.Write("Введите символ: ");
            char symbol = Console.ReadLine()[0];

            //Вывод квадрата
            DrawSquare(size, symbol);
        }
    }
}
