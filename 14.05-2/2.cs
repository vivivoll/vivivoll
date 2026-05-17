using System;
using System.Data;

namespace ConsoleNew
{
    class Pragrams
    {
        static void Main(string[] args)
        {
            //объявление и заполнение массива
            int[] myArray = new int [10] {1,-11,2,22,-3,33,-4,44,5,-55};
            //объявление и указание размера массива
            int[] newArray = new int [10];

            //индексы для распределения
            int minus = 0;
            int plus = 9;

            //цикл: отрицательные слева, положительные справа
            for(int i = 0; i < myArray.Length; i++)
            {
                if(myArray[i] < 0)
                {
                    newArray[minus] = myArray[i];
                    minus++;
                }
                else
                {
                    newArray[plus] = myArray[i];
                    plus--;
                }
            }

            //цикл: вывод результата
            foreach(int i in newArray)
            {
                Console.Write(i + " ");
            }
        }
    }
}