using System;

namespace ConsoleNew
{
    public class Store
    {
        private string name;
        private string address;
        private string description;
        private string phone;
        private string email;

        //Метод ввода данных
        public void setData()
        {
            //Ввод
            Console.Write("Название: ");
            string nameStr = Console.ReadLine();

            Console.Write("Адрес: ");
            string yearsStr = Console.ReadLine();

            Console.Write("Описание: ");
            string descriptionStr = Console.ReadLine();

            Console.Write("Телефон: ");
            string phoneStr = Console.ReadLine();

            Console.Write("Почта: ");
            string emailStr = Console.ReadLine();

            //Присвоение
            name = nameStr;
            address = yearsStr;
            description = descriptionStr;
            phone = phoneStr;
            email = emailStr;
        }

        //Метод вывода данных
        public void getData()
        {
            Console.WriteLine("Название: " + name);
            Console.WriteLine("Адрес: " + address);
            Console.WriteLine("Описание: " + description);
            Console.WriteLine("Телефон: " + phone);
            Console.WriteLine("Почта: " + email);
        }

        //Методы ввода конкретных данных
        //Название
        public void setName()
        {
            Console.WriteLine("Название: ");
            string nameStr = Console.ReadLine();
            name = nameStr;
        }

        public string getName()
        {
            return name;
        }

        //Адрес
        public void setYears()
        {
            Console.WriteLine("Адрес: ");
            string yearsStr = Console.ReadLine();
            address = yearsStr;
        }

        public string getYears()
        {
            return address;
        }

        //Описание
        public void setDescription()
        {
            Console.WriteLine("Описание: ");
            string descriptionStr = Console.ReadLine();
            description = descriptionStr;
        }

        public string getDescription()
        {
            return description;
        }

        //Телефон
        public void setPhone()
        {
            Console.WriteLine("Телефон: ");
            string phoneStr = Console.ReadLine();
            phone = phoneStr;
        }

        public string getPhone()
        {
            return phone;
        }

        //Почта
        public void setEmail()
        {
            Console.WriteLine("Почта: ");
            string emailStr = Console.ReadLine();
            email = emailStr;
        }

        public string getEmail()
        {
            return email;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            //Объект
            Store myStore = new Store();

            //Методы
            myStore.setData();
            myStore.getData();
        }
    }
}
