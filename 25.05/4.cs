using System;

namespace ConsoleNew
{
    class Figura
    {
        public string Name { get; set; }
        public double Square { set; get; }

        //Метод присваивания
        public Figura(string name, double square)
        {
            Name = name;
            Square = square;
        }

        //Метод вывода
        public void Print()
        {
            Console.WriteLine("Фигура: " + Name);
            Console.WriteLine("Площадь: " + Square);
        }
    }

    //наследованный класс
    class Rectangle : Figura
    {
        public double Widht { set; get; }
        public double Height { set; get; }

        //Метод присваивания и вычисления
        public Rectangle(string name, double square, double widht, double height) : base(name, widht * height) {}
    }

    //наследованный класс
    class Circle: Figura
    {
        public double radius { set; get; }

        //Метод присваивания и вычисления
        public Circle(string name, double square, double radius) : base(name, 3.14 * (radius * radius)) {}
    }

    //насоедованный класс
    class Triangle: Figura
    {
        public double a;
        public double b;

        //Метод присваивания и вычисления
        public Triangle(string name, double square, double a, double b): base(name, (a * b) / 2) {}
    }

    //наследованный класс
    class Trapezoid: Figura
    {
        public double a;
        public double b;
        public double h;

        //Метод присваивания и вычисления
        public Trapezoid(string name, double square, double a, double b, double h): base(name, (a + b) / 2 * h) {}
    }

    class Program
    {
        static void Main(string[] args)
        {
            //создание объектов
            Rectangle rectangle = new Rectangle("Прямоугольник", 0, 5, 10);
            Circle circle = new Circle("Круг", 0, 10);
            Triangle triangle = new Triangle("Треугольник", 0, 4, 5);
            Trapezoid trapezoid = new Trapezoid("Трапеция", 0, 5, 7, 2);

            //вывод
            rectangle.Print();
            Console.WriteLine();
            circle.Print();
            Console.WriteLine();
            triangle.Print();
            Console.WriteLine();
            trapezoid.Print();
        }
    }
}