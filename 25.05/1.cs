using System;

namespace ConsoleNew
{
    //Абстрактный класс
    class Human
    {
        public string Name { set; get; }    
        public int Age { set; get; }

        //Метод присваивания
        public Human(string name, int age)
        {
            Name = name;
            Age = age;
        }

        //Метод вывода
        public void PrintHuman()
        {
            Console.WriteLine("Имя: " + Name);
            Console.WriteLine("Возраст: " + Age);
        }
    }

    //Наследованный класс
    class Builder : Human
    {
        public string Worker { get; set; }

        //Метод присваивания
        public Builder(string name, int age, string worker) : base(name, age)
        {
            Worker = worker;
        }

        //Метод вывода
        public void PrintBuilder()
        {
            base.PrintHuman();
            Console.WriteLine("Специальность: " + Worker);
        }
    }

    //Наследованный класс
    class Sailor : Human
    {
        public string Worker_1 { set; get; }

        //Метод присваивания
        public Sailor(string name, int age, string worker_1) : base(name, age)
        {
            Worker_1 = worker_1;
        }

        //Метод вывода
        public void PrintSailor()
        {
            base.PrintHuman();
            Console.WriteLine("Специальность: " + Worker_1);
        }
    }

    //Наследованный класс
    class Pilot: Human
    {
        public string Worker_2 { set; get; }

        //Метод присваивания
        public Pilot(string name, int age, string worker_2) : base(name, age)
        {
            Worker_2 = worker_2;
        }

        //Метод вывода
        public void PrintPilot()
        {
            base.PrintHuman();
            Console.WriteLine("Специальность: " + Worker_2);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            //Создание объектов
            Builder builder_1 = new Builder("Алексей", 35, "Строитель");
            Sailor sailor_1 = new Sailor("Богдан", 46, "Моряк");
            Pilot pilot_1 = new Pilot("Александр", 30, "Пилот");

            //Вывод результата
            builder_1.PrintBuilder();
            Console.WriteLine();
            sailor_1.PrintSailor();
            Console.WriteLine();
            pilot_1.PrintPilot();
            
            Console.WriteLine("Все классы работников");
            

        }
    }
}