using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http.Headers;
using System.Security.Authentication;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace CalculatorWPF
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        //Строки для состояния калькулятора
        private string expression = ""; //Строка ввода
        private string currentNumber = "";  //Текущее число
        private double result = 0;  //Результат
        private string operation = "";  //Текущая операция
        private bool newNumber = true;  //Новое число

        //Метод нажатия на кнопку 
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            //Обработка нажатия
            Button button = (Button)sender;
            string value = button.Content.ToString();

            //Цифры
            if (char.IsDigit(value[0]))
            {
                if (newNumber)
                {
                    currentNumber = value;
                    newNumber = false;
                }
                else
                {
                    if (currentNumber == "0")
                        currentNumber = value;
                    else
                        currentNumber += value;
                }

                expression += value;
                Expression.Text = expression;

                return;
            }

            //Точка
            if (value == ".")
            {
                if (newNumber)
                {
                    currentNumber = "0.";
                    newNumber = false;
                    expression += "0.";
                }
                else if (!currentNumber.Contains("."))
                {
                    currentNumber += ".";
                    expression += ".";
                }

                Expression.Text = expression;
                return;
            }

            //Арифметические операции
            if ("+-*/".Contains(value))
            {
                expression += " " + value + " ";
                Expression.Text = expression;

                Calculate();

                operation = value;
                newNumber = true;
                return;
            }

            // = 
            if (value == "=")
            {
                Calculate();
                Expression.Text = expression;   
                Result.Text = result.ToString();

                operation = "";
                newNumber = true;
                return;
            }

            //CE 
            if (value == "CE")
            {
                currentNumber = "";
                Expression.Text = expression;
                return;
            }

            //C
            if (value == "C")
            {
                expression = "";
                currentNumber = "";
                result = 0;
                operation = "";
                newNumber = true;

                Expression.Text = "";
                Result.Text = "";
                return;
            }

            // <
            if (value == "<")
            {
                if (currentNumber.Length > 0)
                {
                    currentNumber = currentNumber.Remove(currentNumber.Length - 1);
                    expression = expression.Remove(expression.Length - 1);
                }
                Expression.Text = expression;
                return;
            }
        }

        //Функция вычисления
        private void Calculate()
        {
            double num;

            if (!double.TryParse(currentNumber, out num))
                num = 0;

            if (operation == "")
            {
                result = num;
            }
            else
            {
                switch (operation)
                {
                    case "+":
                        result += num;
                        break;
                    case "-":
                        result -= num;
                        break;
                    case "*":
                        result *= num;
                        break;
                    case "/":
                        if (num != 0)
                            result /= num;
                        break;
                }
            }
            currentNumber = "";
        }
    }
}
