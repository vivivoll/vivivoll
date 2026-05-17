using System;

namespace Consoles
{
    class Program
    {
        static void Main(string[] args)
        {
            //объявление массива
            int [] myArray;     
            //заполнение массива              
            myArray = new int [10] {0,2,0,4,0,6,0,8,0,10};

            //объявление нового массива
            int [] newArray;
            //указание размера массива
            newArray = new int [10];
            //счетчик
            int count = 0;  

            //цикл:добавление в новый массив чисел без нулей
            foreach(int i in myArray)
            {
                if(i != 0)
                {
                    newArray[count] = i;
                    count++;
                }
            }

            //цикл: смена пустых мест на -1
            for(int i = 0; i < newArray.Length; i++)
            {
                if(newArray[i] == 0)
                {
                    newArray[i] = -1;
                }
            }

            //вывод результата
            foreach(int i in newArray)
            {
                Console.Write(i + " ");
            }
        }
    }
}