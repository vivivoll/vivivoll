using System;

namespace ConsoleNew
{
    public class Student
    {
        private string surname;
        private string name;
        private string patronymic; //Отчество
        private string group;
        private int age;
        private int[][] grades; //Зубчатый

        //Конструктор с параметрами
        public Student(string surname, string name, string patronymic, string group, int age)
        {
            //Присвоение
            this.surname = surname;
            this.name = name;
            this.patronymic = patronymic;
            this.group = group;
            this.age = age;

            //Массив
            grades = new int[3][];
            grades[0] = new int[10];
            grades[1] = new int[10];
            grades[2] = new int[10];

            //Заполнение массива единицой
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    grades[i][j] = -1;
                }
            }
        }

        //Установка оценки
        public void setGrades(int subject, int index, int grade)
        {
            if (subject < 0 || subject > 2)
            {
                Console.WriteLine("Неверный предмет!");
                return;
            }
            if (index < 0 || index > 9)
            {
                Console.WriteLine("Неверный индекс!");
                return;
            }
            if (grade < 1 || grade > 5)
            {
                Console.WriteLine("Неверная оценка!");
                return;
            }
            grades[subject][index] = grade;
        }

        //Получение оценки
        public int getGrades(int subject, int index)
        {
            if (subject < 0 || subject > 2)
            {
                return -1;
            }
            if (index < 0 || index > 9)
            {
                return -1;
            }
            return grades[subject][index];
        }

        //Средний балл
        public double getAvg(int subject)
        {
            if (subject < 0 || subject > 2)
            {
                return 0;
            }

            int sum = 0;
            int count = 0;

            for (int i = 0; i < 10; i++)
            {
                if (grades[subject][i] != -1)
                {
                    sum += grades[subject][i];
                    count++;
                }
            }
            return sum / count;
        }

        //Вывод
        public void getInfo()
        {
            Console.WriteLine("Фамилия: " + surname);
            Console.WriteLine("Имя: " + name);
            Console.WriteLine("Отчество: " + patronymic);
            Console.WriteLine("Группа: " + group);
            Console.WriteLine("Возраст: " + age);
            Console.WriteLine("Оценки: " + grades);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            //Объект
            Student student_1 = new Student("Иванов", "Иван", "Иванович", "РПО 24/2", 17);

            //Установка оценок
            student_1.setGrades(4, 5, 2);

            //Вывод оценки
            student_1.getGrades(0, 0);

            //Вывод
            student_1.getInfo();
        }
    }
}
