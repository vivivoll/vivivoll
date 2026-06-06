using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace ConsoleNew
{
    [Serializable]   //Пометка для сохранения в файл
    public class Pay
    {
        //Атрибуты
        public double DailyPayment { get; set; }
        public int Days { get; set; }
        public double PenaltyPerDay { get; set; }
        public int DelayDays { get; set; }

        //Атрибуты из вычисления
        public double AmountWithoutPenalty => DailyPayment * Days;
        public double Penalty => PenaltyPerDay * DelayDays;
        public double TotalAmount => AmountWithoutPenalty + Penalty;

        //Пометка для не сохранения в файл
        [NonSerialized]  
        public static bool SerializeComputedFields = true;

        //Конструктор пустой
        public Pay() { }

        //Конструктор по умолчанию
        public Pay(double dailyPayment, int days, double penaltyPerDay, int delayDays)
        {
            DailyPayment = dailyPayment;
            Days = days;
            PenaltyPerDay = penaltyPerDay;
            DelayDays = delayDays;
        }

        //Метод вывода
        public void ToString()
        {
            Console.WriteLine("Оплата за день: " + DailyPayment);
            Console.WriteLine("Количество дней: " + Days);
            Console.WriteLine("Штрафы за день: " + PenaltyPerDay);
            Console.WriteLine("Дни задержки: " + DelayDays);
            Console.WriteLine("Сумма без штрафа: " + AmountWithoutPenalty);
            Console.WriteLine("Штраф: " + Penalty);
            Console.WriteLine("Итог: " + TotalAmount);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string filePath = "file.dat";

            //Создание объекта
            Pay bill = new Pay(1500, 30, 50, 5);

            Console.WriteLine("Исходный счет");
            Console.WriteLine(bill);

            //Сериализация
            //Объект для превращения объекта в байты
            BinaryFormatter formatter = new BinaryFormatter();  
            //Сохранение объекта через поток
            using (FileStream fs = new FileStream(filePath, FileMode.Create))
            {
                formatter.Serialize(fs, bill);
            }

            Console.WriteLine("Сохранено в файл");

            //Десериализация
            using (FileStream fs = new FileStream(filePath, FileMode.Open))
            {
                Pay loaded = (Pay)formatter.Deserialize(fs);
                Console.WriteLine(loaded);
            }
        }
    }
}