using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLibrary1
{
    internal class StringUtils
    {
        // Переворот строки
        public static string Reverse(string s)
        {
            // Проверка на пустую строку
            if (string.IsNullOrEmpty(s)) return s;

            char[] charArray = s.ToCharArray();
            Array.Reverse(charArray);
            return new string(charArray);
        }

        // Подсчет символов
        public static int CountChar(string s, char c)
        {
            // Проверка на пустую строку
            if (string.IsNullOrEmpty(s)) return 0;

            int count = 0;
            foreach (char ch in s)
            {
                if (ch == c) count++;
            }
            return count;
        }

        // Замена вхождений строки
        public static string Replace(string s, string oldStr, string newStr)
        {
            if (s == null) return null;
            return s.Replace(oldStr, newStr);
        }
    }
}
