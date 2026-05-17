using System;

namespace ConsoleNew
{
    class Programs
    {
        static void Main(string[] args)
        {
            //объявление и заполнение массива
            int[] myArray = new int [5] {1,1,1,5,5};

            //Ввод числа и преобразование строки в число
            Console.Write("Введите число для поиска в массиве: ");
            string numberString = Console.ReadLine();
            int number = Convert.ToInt32(numberString);

            //счетчик
            int count = 0;

            for(int i = 0; i < myArray.Length; i++)
            {
                if(myArray[i] == number)
                {
                    count++;
                }
            }
            Console.WriteLine("Это число встречается " + count + " раз");
        }
    }
}