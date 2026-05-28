using System;

namespace CarRacingGame
{
    //делегат
    public delegate void RaceFinishHandler(object sender, RaceEventArgs e);

    //класс определения события
    public class RaceEventArgs : EventArgs
    {
        //переменная имени автомобиля
        public string CarName { get; }
        //переменная позиции
        public int Position { get; }

        //метод присвоения
        public RaceEventArgs(string carName, int position)
        {
            CarName = carName;
            Position = position;
        }
    }

    //абстрактный класс автомобиль
    public abstract class Car
    {
        public string Name { get; set; }
        public int Position { get; protected set; } = 0;
        public int Speed { get; protected set; }

        //событие
        public event RaceFinishHandler Finished;

        //конструктор
        public Car(string name)
        {
            Name = name;
        }

        //абстрактный метод движения
        public abstract void Move();

        //вызов события финиша
        protected void OnFinished()
        {
            Finished?.Invoke(this, new RaceEventArgs(Name, Position));
        }
    }

    //унаследованные классы
    //спортивная машина
    public class SportCar : Car
    {
        public SportCar(string name) : base(name) { }

        public override void Move()
        {
            Random rand = new Random();
            Speed = rand.Next(8, 15);
            Position += Speed;

            if (Position >= 100)
            {
                Position = 100;
                OnFinished();
            }
        }
    }

    //обычная машина
    public class PassengerCar : Car
    {
        public PassengerCar(string name) : base(name) { }

        public override void Move()
        {
            Random rand = new Random();
            Speed = rand.Next(5, 11);
            Position += Speed;

            if (Position >= 100)
            {
                Position = 100;
                OnFinished();
            }
        }
    }

    //класс гонки
    public class Race
    {
        //массив автомобилей
        private Car[] cars = new Car[4];

        //добавление автомобиля
        public void AddCar(Car car, int index)
        {
            cars[index] = car;
            car.Finished += Car_Finished;
        }

        //запуск гонки
        public void StartRace()
        {
            Console.WriteLine("Начало гонки\n");

            bool raceFinished = false;

            //цикл вывода гонки
            while (!raceFinished)
            {
                for (int i = 0; i < cars.Length; i++)
                {
                    if (!raceFinished && cars[i] != null)
                    {
                        cars[i].Move();
                        Console.WriteLine($"{cars[i].Name,-15} | Позиция: {cars[i].Position,3} | Скорость: {cars[i].Speed,2} км/ч");
                    }
                }
                Console.WriteLine();
            }
        }

        //обработчик события
        private void Car_Finished(object sender, RaceEventArgs e)
        {
            Console.WriteLine($"\n Победил: {e.CarName}\n");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            //объект
            Race race = new Race();

            //добавление автомобилей
            race.AddCar(new SportCar("Феррари"), 0);
            race.AddCar(new PassengerCar("Лада"), 1);

            race.StartRace();

            Console.WriteLine("Гонка завершена");
            Console.ReadKey();
        }
    }
}