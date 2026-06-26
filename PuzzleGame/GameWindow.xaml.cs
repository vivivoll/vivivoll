using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;
using PuzzleGame.Models;
using System.IO;

namespace PuzzleGame
{
    public partial class GameWindow : Window
    {
        private int size;
        private List<Tile> tiles = new List<Tile>();
        private DispatcherTimer timer;
        private int seconds = 0;
        private int moves = 0;
        private int selectedIndex = -1;
        private Button selectedButton;

        //путь к картинке
        private string imagePath;
        public GameWindow(int gameSize, string path)
        {
            InitializeComponent();

            size = gameSize;
            imagePath = path;

            PuzzleGrid.Rows = size;
            PuzzleGrid.Columns = size;

            LoadImage();
            Shuffle();
            Draw();
            StartTimer();
        }

        //запуск таймера
        private void StartTimer()
        {
            timer = new DispatcherTimer();
            timer.Interval = TimeSpan.FromSeconds(1);
            timer.Tick += Timer_Tick;
            timer.Start();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            seconds++;
            tbTime.Text = "Время: " +
                TimeSpan.FromSeconds(seconds).ToString(@"mm\:ss");
        }

        //загрузка и разрезание изображения
        private void LoadImage()
        {
            BitmapImage image = new BitmapImage(new Uri(imagePath));

            tiles.Clear();

            for (int y = 0; y < size; y++)
            {
                for (int x = 0; x < size; x++)
                {
                    ImageBrush brush = new ImageBrush(image);

                    brush.ViewboxUnits = BrushMappingMode.RelativeToBoundingBox;

                    brush.Viewbox = new Rect(
                        (double)x / size,
                        (double)y / size,
                        1.0 / size,
                        1.0 / size);

                    tiles.Add(new Tile
                    {
                        Brush = brush,
                        CorrectPosition = y * size + x
                    });
                }
            }
        }

        //перемешивание
        private void Shuffle()
        {
            Random rnd = new Random();
            tiles = tiles.OrderBy(x => rnd.Next()).ToList();
        }

        private void Shuffle_Click(object sender, RoutedEventArgs e)
        {
            Shuffle();
            moves = 0;
            seconds = 0;
            Draw();
        }

        //отрисовка поля
        private void Draw()
        {
            PuzzleGrid.Children.Clear();

            for (int i = 0; i < tiles.Count; i++)
            {
                Button btn = new Button();

                btn.Style = (Style)FindResource("PuzzleButtonStyle");

                btn.Tag = i;
                btn.Margin = new Thickness(1);
                btn.Click += Tile_Click;

                btn.Background = tiles[i].Brush;

                PuzzleGrid.Children.Add(btn);
            }

            tbMoves.Text = $"Ходы: {moves}";
        }

        //клик по плитке
        private void Tile_Click(object sender, RoutedEventArgs e)
        {
            Button btn = sender as Button;
            int index = (int)btn.Tag;

            if (selectedIndex == -1)
            {
                selectedIndex = index;
                selectedButton = btn;

                btn.BorderThickness = new Thickness(3);
                btn.BorderBrush = (Brush)new BrushConverter()
                    .ConvertFrom("#38BDF8");

                return;
            }

            if (selectedIndex == index)
            {
                selectedIndex = -1;
                return;
            }

            if (selectedButton != null)
            {
                selectedButton.BorderThickness = new Thickness(0);
            }

            Swap(selectedIndex, index);

            selectedIndex = -1;
            moves++;

            Draw();
            CheckWin();
        }

        //обмен плиток
        private void Swap(int a, int b)
        {
            var temp = tiles[a];
            tiles[a] = tiles[b];
            tiles[b] = temp;
        }

        //проверка победы
        private void CheckWin()
        {
            for (int i = 0; i < tiles.Count; i++)
            {
                if (tiles[i].CorrectPosition != i)
                    return;
            }

            timer.Stop();

            File.AppendAllText("Records.txt",
                $"Поле {size}x{size} | Время: {seconds} сек | Ходы: {moves}\n");

            MessageBox.Show(
                $"Победа!\n\nВремя: {TimeSpan.FromSeconds(seconds):mm\\:ss}\nХоды: {moves}",
                "Игра окончена");
        }

        //показать оригинал
        private void ShowImage_Click(object sender, RoutedEventArgs e)
        {
            Window preview = new Window();

            preview.Title = "Оригинальное изображение";
            preview.Width = 500;
            preview.Height = 500;

            Image img = new Image();

            img.Source = new BitmapImage(new Uri(imagePath));
            img.Stretch = Stretch.Uniform;

            preview.Content = img;

            preview.ShowDialog();
        }
    }
}