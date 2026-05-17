using System;
using System.Collections.Generic;

namespace ConsoleNew
{
    class Programs
    {
        static int[] FilterArray(int[] original, int[] filterData)
        {
            List<int> result = new List<int>();

            foreach (int item in original)
            {
                //добавляем элемент только если его нет в массиве фильтра
                bool found = false;
                for (int i = 0; i < filterData.Length; i++)
                {
                    if (filterData[i] == item)
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    result.Add(item);
                }
            }

            return result.ToArray();
        }

        static void Main(string[] args)
        {
            //Оригинальный массив
            int[] original = { 1, 2, 6, -1, 88, 7, 6 };

            //Массив для фильтрации
            int[] filterData = { 6, 88, 7 };

            //Фильтрация и вывод результата
            int[] result = FilterArray(original, filterData);

            Console.Write("Результат: ");
            Console.WriteLine(string.Join(" ", result));
        }
    }
}
