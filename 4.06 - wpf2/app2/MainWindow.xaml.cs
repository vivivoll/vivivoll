using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
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

namespace WpfApp2
{
    public partial class MainWindow : Window
    {
        //Константы WinAPI
        private const int SM_CXSCREEN = 0;  //Ширина 
        private const int SM_CYSCREEN = 1;  //Высота 

        //Вызов функции из user32.dll 
        [DllImport("user32.dll")]
        private static extern int GetSystemMetrics(int nIndex);

        public MainWindow()
        {
            InitializeComponent();
        }

        private void CalculateDiagonal_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                //Высота и ширина
                int width = GetSystemMetrics(SM_CXSCREEN);
                int height = GetSystemMetrics(SM_CYSCREEN);

                //Диагональ монитора
                double diagonalPixels = Math.Sqrt(width * width + height * height);
                double diagonalInches = diagonalPixels / 96.0;   

                //Вывод
                tbResult.Text = $"Размер вашего монитора:\n\n" +
                               $"Ширина: {width} пикселей\n" +
                               $"Высота: {height} пикселей\n\n" +
                               $"Диагональ: {diagonalInches} дюймов";
            }
            catch (Exception ex)
            {
                tbResult.Text = "Ошибка: " + ex.Message;
            }
        }
    }
}
