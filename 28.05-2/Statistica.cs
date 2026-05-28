using System;

namespace ConsoleNew
{
    class Program
    {
        static void Main(string[] args)
        {
            string text = "вот дом, который построил джек. а это пшеница, которая в темном чулане хранится в доме, который построил джек. а это веселая птица-синица, которая часто ворует пшеницу, которая в темном чулане хранится в доме, который построил джек";
            
            //Список знаков препинания
            char[] separators = {' ', ',', '.', '!', '-', '?', ':', ';'};

            //Убираются знаки препинания
            string[] words = text.Split(separators);

            //Словарь
            Dictionary<string, int> statistics = new Dictionary<string, int>();

            //Цикл добавления слов в словарь
            foreach(string word in words)
            {
                //Если слово уже есть
                if (statistics.ContainsKey(word))
                {
                    statistics[word]++;
                }
                //Если слово новое
                else
                {
                    statistics[word] = 1;
                }
            }

            //Вывод
            Console.WriteLine("Исходный текст");
            Console.WriteLine(text);
            Console.WriteLine();

            Console.WriteLine("Слово | Количество");
            //Цикл вывода ключа и значения
            foreach(var pair in statistics)
            {
                Console.WriteLine($"{pair.Key} | {pair.Value}");
            }           
        }
    }
}