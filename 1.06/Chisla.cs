using System;

namespace ConsoleNew
{
    class Program
    {
        static void Main()
        {
            int[] results = new int[3];  //Массив 
            int index = 0;               //Счетчик 

            while (true)
            {
                try
                {
                    //Ввод чисел
                    Console.WriteLine("\nВведите первое целое число:");
                    string num1Str = Console.ReadLine();
                    int num1 = Convert.ToInt32(num1Str);

                    Console.WriteLine("Введите второе целое число:");
                    string num2Str = Console.ReadLine();
                    int num2 = Convert.ToInt32(num2Str);

                    //Результат
                    int result = num1 / num2;
                    results[index] = result;
                    index++;

                    Console.WriteLine($"Результат: {num1} / {num2} = {result}");
                }
                //Исключения
                catch (FormatException)
                {
                    Console.WriteLine("Ошибка: введите целое число");
                }
                catch (DivideByZeroException)
                {
                    Console.WriteLine("Ошибка: деление на ноль невозможно");
                }
                catch (IndexOutOfRangeException)
                {
                    Console.WriteLine("Массив результатов заполнен, дальнейшие вычисления невозможны");
                    break;
                }
                finally
                {
                    Console.WriteLine("Попытка выполнения операции завершена");
                }

                //Продолжить или нет
                Console.WriteLine("\nХотите продолжить?");
                Console.WriteLine("1 - Да");
                Console.WriteLine("2 - Нет");
                Console.Write("Ваш выбор: ");

                string choice = Console.ReadLine();

                if (choice == "2")
                {
                    break;
                }
            }
        }
    }
}