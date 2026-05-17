using System;

namespace ConsoleNew
{
    public class Journal
    {
        //Атрибуты
        private string name;
        private int years;
        private string description;
        private string phone;
        private string email;

        //Метод ввода данных
        public void setData()
        {
            //Ввод
            Console.Write("Название: ");
            string nameStr = Console.ReadLine();

            Console.Write("Год основания: ");
            string yearsStr = Console.ReadLine();
            int yearsInt = Convert.ToInt32(yearsStr);

            Console.Write("Описание: ");
            string descriptionStr = Console.ReadLine();

            Console.Write("Телефон: ");
            string phoneStr = Console.ReadLine();

            Console.Write("Почта: ");
            string emailStr = Console.ReadLine();

            //Присвоение
            name = nameStr;
            years = yearsInt;
            description = descriptionStr;
            phone = phoneStr;
            email = emailStr;
        }

        //Метод вывода данных
        public void getData()
        {
            Console.WriteLine("Название: " + name);
            Console.WriteLine("Год основания: " + years);
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

        //Год основания
        public void setYears()
        {
            Console.WriteLine("Год основания: ");
            string yearsStr = Console.ReadLine();
            int yearsInt = Convert.ToInt32(yearsStr);
            years = yearsInt;
        }

        public int getYears()
        {
            return years;
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
            //Создание объекта
            Journal myJournal = new Journal();

            //Вызов методов
            myJournal.setData();
            myJournal.getData();

            myJournal.setEmail();
            myJournal.getEmail();
        }
    }
}
