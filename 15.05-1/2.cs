using System;

namespace ConsoleNew
{
    class Program
    {
        static void Main(string[] args)
        {
            //Ввод строки
            Console.WriteLine("Введите строку из 0 и 1: ");
            string numStr = Console.ReadLine();

            try
            {
                //Преобразование строки в десятичную
                int num = Convert.ToInt32(numStr, 2);
                Console.WriteLine("В десятичной " + numStr + ": " + num);
            }
            //Исплючения
            //Формат
            catch (FormatException)
            {
                Console.WriteLine("Неправильный формат!");
            }
            //Диапазон
            catch (OverflowException)
            {
                Console.WriteLine("Вне диапазона!");
            }
        }
    }
}
