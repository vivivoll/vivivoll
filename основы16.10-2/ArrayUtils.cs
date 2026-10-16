using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLibrary1
{
    public static class ArrayUtils
    {
        // Поиск минимального
        public static T Minimum<T>(T[] arr) where T : IComparable<T>
        {
            if (arr == null || arr.Length == 0)
                throw new ArgumentException("Пустой массив");
            T min = arr[0];
            for (int i = 1; i < arr.Length; i++)
            {
                if (arr[i].CompareTo(min) < 0)
                {
                    min = arr[i];
                }
            }
            return min;
        }

        // Сортировка
        public static T[] SortArray<T>(T[] arr)
        {
            if (arr == null) return null;

            T[] clone = (T[])arr.Clone();
            Array.Sort(clone);
            return clone;
        }

        // Удаление дубликатов
        public static T[] RemoveDuplicates<T>(T[] arr)
        {
            if (arr == null) return null;

            HashSet<T> seen = new HashSet<T>(); 

            foreach (T item in arr)
            {
                seen.Add(item);
            }
            return seen.ToArray();
        }


    }
}
