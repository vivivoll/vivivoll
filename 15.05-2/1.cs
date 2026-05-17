using System;

namespace ConsoleNew
{
    public class WebSite
    {
        private string name;
        private string path;
        private string despciption;
        private string ipAddress;

        //Метод ввода данных
        public void setData()
        {
            //Ввод данных
            Console.Write("Название: ");
            string nameStr = Console.ReadLine();

            Console.Write("Путь: ");
            string pathStr = Console.ReadLine();

            Console.Write("Описание: ");
            string despciptionStr = Console.ReadLine();

            Console.Write("Ip-Адрес: ");
            string ipAddressStr = Console.ReadLine();

            //Присванивание введенных данных
            name = nameStr;
            path = pathStr;
            despciption = despciptionStr;
            ipAddress = ipAddressStr;
        }

        //Метод вывода данных
        public void getData()
        {
            Console.WriteLine("Название: " + name);
            Console.WriteLine("Путь: " + path);
            Console.WriteLine("Описание: " + despciption);
            Console.WriteLine("Ip-Адрес: " + ipAddress);
        }

        //Методы для отдельных полей
        //Название
        public void setName()
        {
            Console.Write("Название: ");
            string nameStr = Console.ReadLine();
            name = nameStr;
        }

        public string getName()
        {
            return name;
        }

        //Путь
        public void setPath()
        {
            Console.Write("Путь: ");
            string pathStr = Console.ReadLine();
            path = pathStr;
        }

        public string getPath()
        {
            return path;
        }

        //Описание
        public void setDescription()
        {
            Console.Write("Описание: ");
            string despciptionStr = Console.ReadLine();
            despciption = despciptionStr;
        }

        public string getDescription()
        {
            return despciption;
        }

        //Ip
        public void setIp()
        {
            Console.Write("Ip: ");
            string ipStr = Console.ReadLine();
            ipAddress = ipStr;
        }

        public string getIp()
        {
            return ipAddress;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            //Создание объекта
            WebSite mySite = new WebSite();

            //Вызов методов
            mySite.setData();
            mySite.getData();

            mySite.setIp();
            mySite.getIp();
        }
    }
}
