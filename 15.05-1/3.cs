using System;

namespace ConsoleNew
{
    public class Card
    {
        //Атрибуты
        private long numberCard;
        private string fullName;
        private int cvc;
        private string dateEnd;

        //Конструктор с параметрами
        public Card(long numberCard, string fullName, int cvc, string dateEnd)
        {
            //Проверка номера карты
            if (numberCard < 1000000000000000 || numberCard > 9999999999999999)
            {
                throw new Exception("Номер карты должен быть 16-значным!");
            }

            //Проверка ФИО
            if (fullName == "" || fullName == null)
            {
                throw new Exception("ФИО не может быть пустым!");
            }

            //Проверка cvc
            if (cvc < 0 || cvc > 999)
            {
                throw new Exception("CVC должен быть от 0 до 999!");
            }

            //Проверка даты
            if (dateEnd == "" || dateEnd == null)
            {
                throw new Exception("Ошибка: дата не может быть пустой!");
            }

            //Сохранение значений
            this.numberCard = numberCard;
            this.fullName = fullName;
            this.cvc = cvc;
            this.dateEnd = dateEnd;
        }

        //Метод вывода
        public void print()
        {
            Console.WriteLine("Номер карты: " + numberCard);
            Console.WriteLine("ФИО: " + fullName);
            Console.WriteLine("CVC: " + cvc);
            Console.WriteLine("Дата окончания работы карты: " + dateEnd);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                //Объект
                Card myCard = new Card(1100303057578484, "Иванов Иван Иванович", 456, "25.12.2030");
                //Вывод
                myCard.print();
            }
            //Исключение
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
