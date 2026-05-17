using System;

namespace ConsoleNew
{
    class Program
    {
        static void Main(string[] args)
        {
            //Ввод строки
            Console.WriteLine("Введите арифметическую строку: ");
            string numStr = Console.ReadLine();

            try
            {
                //Проверка на пустоту
                if (numStr == "")
                {
                    throw new("Строка пустая!");
                }

                //Разбиение на *
                string[] num = numStr.Split("*"); //Разбивка на *

                //Проверка ввода
                if (num.Length < 1 || num[0] == "")
                {
                    throw new("Неправильный ввод!");
                }

                //Преобразование первого элемента
                int result = Convert.ToInt32(num[0]);

                //Цикл умножения выражения
                for (int i = 1; i < num.Length; i++)
                {
                    int sum = Convert.ToInt32(num[i]);
                    result = result * sum;
                }
                //Вывод
                Console.WriteLine("Результат: " + result);
            }
            //Исключения
            catch (FormatException)
            {
                Console.WriteLine("Ошибка: неправильный формат");
            }
            catch (OverflowException)
            {
                Console.WriteLine("Ошибка: вне диапазона int!");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
