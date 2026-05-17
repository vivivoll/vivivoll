using System;

namespace ConsoleNew
{
    class Program
    {
        static void Main(string[] args)
        {
            //Ввод строки
            Console.WriteLine("Введите число (0-9): ");
            string numStr = Console.ReadLine();

            try
            {
                //Преобразование
                int num = Convert.ToInt32(numStr);

                //Проверка диапазона
                if (num > 0 && num < 10)
                {
                    Console.WriteLine("Число: " + num);
                }
                else
                {
                    Console.WriteLine("Число вне диапазона!");
                }
            }
            //Не формат числа
            catch (FormatException)
            {
                Console.WriteLine("Неправильный формат!");
            }
            //Не диапазон int
            catch (OverflowException)
            {
                Console.WriteLine("Число вне диапазона int!");
            }
        }
    }
}
