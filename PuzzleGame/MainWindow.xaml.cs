using System.IO;
using System.Windows;
using Microsoft.Win32;

namespace PuzzleGame
{
    public partial class MainWindow : Window
    {
        //путь к картинке
        private string selectedImagePath = "";
        public MainWindow()
        {
            InitializeComponent();
        }

        private void ChooseImage_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();

            dialog.Filter = "Изображения (*.jpg;*.jpeg;*.png)|*.jpg;*.jpeg;*.png";

            if (dialog.ShowDialog() == true)
            {
                selectedImagePath = dialog.FileName;

                tbImage.Text = Path.GetFileName(selectedImagePath);
            }
        }

        private void OpenGame(int size)
        {
            if (string.IsNullOrEmpty(selectedImagePath))
            {
                MessageBox.Show(
                    "Сначала выберите изображение!",
                    "Ошибка",
                    MessageBoxButton.OK,
                    MessageBoxImage.Warning);
                return;
            }

            GameWindow game = new GameWindow(size, selectedImagePath);

            game.ShowDialog();
        }

        private void Btn3_Click(object sender, RoutedEventArgs e)
        {
            OpenGame(3);
        }
        private void Btn4_Click(object sender, RoutedEventArgs e)
        {
            OpenGame(4);
        }
        private void Btn5_Click(object sender, RoutedEventArgs e)
        {
            OpenGame(5);
        }

        //рекорды
        private void Records_Click(object sender, RoutedEventArgs e)
        {
            if (!File.Exists("Records.txt"))
            {
                MessageBox.Show("Рекордов пока нет.");
                return;
            }

            string text = File.ReadAllText("Records.txt");

            if (string.IsNullOrWhiteSpace(text))
            {
                MessageBox.Show("Рекордов пока нет.");
                return;
            }
            MessageBox.Show(text, "Рекорды");
        }
    }
}