using System;
using System.ComponentModel;
using System.Runtime.InteropServices.Marshalling;

namespace ConsoleNew
{
    //Абстрактный класс
    class Passport
    {
        public int Number { set; get; }
        public int Seriya { set; get; }

        //Метод присваивания
        public Passport(int number, int seriya)
        {
            Number = number;
            Seriya = seriya;
        }

        //Метод вывода
        public void PrintPassport()
        {
            Console.WriteLine("Номер: " + Number);
            Console.WriteLine("Серия: " + Seriya);
        }
    }

    //Наследованный класс
    class ZagranPassport : Passport
    {
        public int NumberViza { set; get; }
        public int NumberZagran { set; get; }

        //Метод присваивания
        public ZagranPassport(int number, int seriya, int numberviza, int numberzagran) : base(number, seriya)
        {
            NumberViza = numberviza;
            NumberZagran = numberzagran;
        }

        //Метод вывода
        public void PrintZagran()
        {
            base.PrintPassport();
            Console.WriteLine("Номер визы: " + NumberViza);
            Console.WriteLine("Номер загранпаспорта: " + NumberZagran);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            //Создание объектов
            Passport passport = new Passport(4563, 463067);
            ZagranPassport zagranPassport = new ZagranPassport(passport.Number, passport.Seriya, 12312, 1123123);

            //Вывод
            Console.WriteLine("Паспорт:");
            passport.PrintPassport();
            Console.WriteLine();

            Console.WriteLine("Загранпаспорт:");
            zagranPassport.PrintZagran();
        }
    }
}