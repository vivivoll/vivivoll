using System;
using System.Globalization;
using System.Security;
using System.Security.AccessControl;

namespace ConsoleNew
{
    //Абстрактный класс
    abstract class Figura
    {
        public abstract double SquareFigure();  //Метод площадь

        public abstract double PerimeterFigure();   //Метод периметр
    }

    //Наследники
    //Треугольник
    class Triangle : Figura
    {
        public double A { set; get; }
        public double B { set; get; }
        public double C { set; get; }
        public double H { set; get; }

        //Метод присваивания
        public Triangle(double a, double b, double c, double h)
        {
            A = a;
            B = b;
            C = c;
            H = h;
        }

        //Метод расчета площади
        public override double SquareFigure()
        {
            return (1.0/2.0) * A * H;
        }

        //Метод расчета периметра
        public override double PerimeterFigure()
        {
            return A + B + C;
        }

    }

    //Квадрат
    class Square : Figura
    {
        public double A { set; get; }

        //Метод присваивания
        public Square(double a)
        {
            A = a;
        }

        //Метод расчета площади
        public override double SquareFigure()
        {
            return A * A;
        }

        //Метод расчета периметра
        public override double PerimeterFigure()
        {
            return 4.0 * A;
        }
    }

    //Ромб
    class Rhomb : Figura
    {
        public double A { set; get; }
        public double H { set; get; }

        public Rhomb(double a, double h)
        {
            A = a;
            H = h;
        }

        public override double SquareFigure()
        {
            return A * H;
        }

        public override double PerimeterFigure()
        {
            return 4.0 * A;
        }
    }

    //Прямгугольник
    class Rectangle : Figura
    {
        public double A { set; get; }
        public double B { set; get; }

        public Rectangle(double a, double b)
        {
            A = a;
            B = b;
        }

        public override double SquareFigure()
        {
            return A * B;
        }

        public override double PerimeterFigure()
        {
            return (A * 2.0) + (B * 2.0);
        }
    }

    //Параллелограмм
    class Parallelogram : Figura
    {
        public double A { set; get; }
        public double B { set; get; }
        public double H { set; get; }

        public Parallelogram(double a, double b, double h)
        {
            A = a;
            B = b;
            H = h;
        }

        public override double SquareFigure()
        {
            return A * H;
        }

        public override double PerimeterFigure()
        {
            return 2.0 * (A + B);
        }
    }

    //Трапеция
    class Trapezoid : Figura
    {
        public double A { set; get; }
        public double B { set; get; }
        public double C { set; get; }
        public double D { set; get; }
        public double H { set; get; }

        public Trapezoid(double a, double b, double c, double d, double h)
        {
            A = a;
            B = b;
            C = c;
            D = d;
            H = h;
        }

        public override double SquareFigure()
        {
            return ((A + B ) / 2.0) * H;
        }

        public override double PerimeterFigure()
        {
            return A + B + C + D;
        }
    }

    //Круг
    class Circle: Figura
    {
        public double P = 3.14;
        public double R { set; get; }

        public Circle(double p, double r)
        {
            P = p;
            R = r;
        }

        public override double SquareFigure()
        {
            return P * (R * R);
        }

        public override double PerimeterFigure()
        {
            return 2.0 * P * R;
        }
    }

    //Эллипс
    class Ellipse : Figura
    {
        public double P = 3.14;
        public double A { set; get; }
        public double B { set; get; }

        public Ellipse(double a, double b)
        {
            A = a;
            B = b;
        }

        public override double SquareFigure()
        {
            return P * A * B;
        }

        public override double PerimeterFigure()
        {
            return Math.Sqrt(((A * A ) + (B * B)) / 2.0);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            
        }
    }
}