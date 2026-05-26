using System;

namespace ConsoleNew
{
    //Абстрактный класс
    class Animal
    {
        public string Name { set ; get; }
        public string TypeAnimal { set; get; }

        //Метод присваивания
        public Animal(string name, string typeanimal)
        {
            Name = name;
            TypeAnimal = typeanimal;
        }

        //Метод вывода
        public void PrintAnimal()
        {
            Console.WriteLine("Животное: " + Name);
            Console.WriteLine("Характеристика: " + TypeAnimal);
        }
    }

    //Наследованный класс
    class Tigr : Animal
    {
        //Метод присваивания
        public Tigr(string name, string typeanimal) : base(name, typeanimal) {}
    }

    //Наследованный класс
    class Crocodile : Animal
    {
        //Метод присваивания
        public Crocodile(string name, string typeanimal) : base(name, typeanimal) {}
    }

    //Наследованный класс
    class Kenguru: Animal
    {
        //Метод присваивания
        public Kenguru(string name, string typeanimal) : base(name, typeanimal) {}
    }

    class Program
    {
        static void Main(string[] args)
        {
            //Создание объектов
            Tigr tigr = new Tigr("Тигр", "Хищник");
            Crocodile crocodile = new Crocodile("Крокодил", "Хищник");
            Kenguru kenguru = new Kenguru("Кенгуру", "Млекопитающее");

            //Вывод
            tigr.PrintAnimal();
            Console.WriteLine();
            crocodile.PrintAnimal();
            Console.WriteLine();
            kenguru.PrintAnimal();
        }
    }
}