using System;

namespace ConsoleNew
{

    //Аьстрактный класс
    abstract class Product
    {
        public string Id { get; set; }
        public string Name { get; set; }
        public double Price { get; set; }
        public double Weight { get; set; }

        //Метод присваивания
        protected Product(string id, string name, double price, double weight)
        {
            Id = id;
            Name = name;
            Price = price;
            Weight = weight;
        }
    }

    //Продукты питания
    class FoodProduct : Product
    {
        public string Date { get; set; } 
        public double Temperature { get; set; } 

        public FoodProduct(string id, string name, double price, double weight, string date, double temp) 
            : base(id, name, price, weight)
        {
            Date = date;
            Temperature = temp;
        }
    }

    //Бытовая химия
    class ChemicalProduct : Product
    {
        public string HazardClass { get; set; } 

        //Метод присваивания
        public ChemicalProduct(string id, string name, double price, double weight, string hazardClass) 
            : base(id, name, price, weight)
        {
            HazardClass = hazardClass;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            
        }
    }
}