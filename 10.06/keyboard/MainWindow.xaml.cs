using System;
using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;

namespace KeyboardTrainer
{
    public partial class MainWindow : Window
    {
        //Основные атрибуты
        private string targetText = ""; //Текущий текст
        private int currentIndex = 0;   //Позиция текущего символа
        private int correctChars = 0;   //Правильно
        private int errors = 0;         //Неправильно
        private DateTime sessionStart;  //Начало тренировки
        private bool isSessionActive = false;   //Старт-Стоп

        //Словарь для клавиш клавиатуры и кнопок
        private Dictionary<Key, Button> keyboardButtons = new Dictionary<Key, Button>();

        //Цвета рядов клавиатуры
        private readonly Brush[] rowColors =
        {
            Brushes.LightCoral,
            Brushes.Orange,
            Brushes.LightGoldenrodYellow,
            Brushes.LightGreen,
            Brushes.LightSkyBlue
        };

        public MainWindow()
        {
            InitializeComponent();
            CreateKeyboard();
        }

        //Создание клавиатуры
        private void CreateKeyboard()
        {
            //Строки с клавишами
            string[] rows =
            {
                "` 1 2 3 4 5 6 7 8 9 0 - = Backspace",
                "Tab q w e r t y u i o p [ ] \\",
                "Caps a s d f g h j k l ; ' Enter",
                "Shift z x c v b n m , . / Shift",
                "Ctrl Win Alt Space Alt Win Ctrl"
            };

            //Очистка клавиатуры
            KeyboardGrid.Children.Clear();

            //Массив создан
            for (int rowIndex = 0; rowIndex < rows.Length; rowIndex++)
            {
                //Создания ряда клавиш
                var rowPanel = new StackPanel
                {
                    Orientation = Orientation.Horizontal,   //Горизонтальное расположение
                    HorizontalAlignment = HorizontalAlignment.Center,   //По центру окна
                    Margin = new Thickness(0, 6, 0, 6)  //Отступы
                };

                //Разбивка клавиш через массив
                foreach (string keyText in rows[rowIndex].Split(' '))
                {
                    //Новая кнопка
                    Button btn = new Button
                    {
                        Content = keyText.Replace("Backspace", "←").Replace("Caps", "CapsLock"),
                        Height = 58,
                        Width = 58,
                        Margin = new Thickness(3, 0, 3, 0), //Отступы между кнопками
                        Background = rowColors[rowIndex],   //Цвет ряда
                        FontSize = 14,
                    };

                    rowPanel.Children.Add(btn); //Добавление кнопки в след ряд

                    //Присвоение клавише кнопку 
                    if (TryGetKey(keyText, out Key key))
                        keyboardButtons[key] = btn;
                }
                //Добавление ряда
                KeyboardGrid.Children.Add(rowPanel);
            }
        }

        private bool TryGetKey(string keyText, out Key key)
        {
            key = Key.None; //По умолчанию
            string normalized = keyText.ToUpper(); //Верхний регистр
            return Enum.TryParse(normalized, true, out key);    //Преобразование строки в Key
        }

        //Нажатие на клавиши
        private void Window_PreviewKeyDown(object sender, KeyEventArgs e)
        {
            //Подсветка клавиши
            if (keyboardButtons.TryGetValue(e.Key, out Button btn))
                btn.Background = Brushes.Orange;

            //Проверка старта 
            if (!isSessionActive) return;

            //Проверка текущих символов для ввода
            if (currentIndex < targetText.Length)
            {
                char expected = targetText[currentIndex];   //Символ для ввода
                char pressed = GetCharFromKey(e.Key, Keyboard.Modifiers);   //Введенный символ

                //Сравнение ввода
                bool isCorrect = cbCaseSensitive.IsChecked == true ? pressed == expected : char.ToLower(pressed) == char.ToLower(expected);

                //Проверка правильности ввода
                if (isCorrect)
                    correctChars++;
                else
                    errors++;

                currentIndex++;
                UpdateStats();

                //Окончание программы при вводе всех символов
                if (currentIndex >= targetText.Length)
                    EndSession();
            }
        }

        //Метод обработки клавиш
        private char GetCharFromKey(Key key, ModifierKeys modifiers)
        {
            //Проверка нажатого шифта
            bool shiftPressed = (modifiers & ModifierKeys.Shift) == ModifierKeys.Shift;
            //Проверка нажатого капслока с помощью метода из урока
            bool capsLockOn = Keyboard.IsKeyToggled(Key.CapsLock);

            //Обработка букв
            if (key >= Key.A && key <= Key.Z)
            {
                char letter = key.ToString()[0];
                bool shouldBeUpper = shiftPressed ^ capsLockOn; //Логика регистра
                return shouldBeUpper ? char.ToUpper(letter) : char.ToLower(letter); //Возврат клавиши с регистром
            }

            //ОБработка цифр и символов
            switch (key)
            {
                case Key.D0: return shiftPressed ? ')' : '0';
                case Key.D1: return shiftPressed ? '!' : '1';
                case Key.D2: return shiftPressed ? '@' : '2';
                case Key.D3: return shiftPressed ? '#' : '3';
                case Key.D4: return shiftPressed ? '$' : '4';
                case Key.D5: return shiftPressed ? '%' : '5';
                case Key.D6: return shiftPressed ? '^' : '6';
                case Key.D7: return shiftPressed ? '&' : '7';
                case Key.D8: return shiftPressed ? '*' : '8';
                case Key.D9: return shiftPressed ? '(' : '9';
                default: return ' ';
            }
        }

        //Метод обработки отпускания клавиши
        private void Window_KeyUp(object sender, KeyEventArgs e)
        {
            //Проверка кнопки и отпущенной клавиши
            if (keyboardButtons.TryGetValue(e.Key, out Button btn))
            {
                int rowIndex = GetRowIndex(e.Key);
                btn.Background = rowColors[rowIndex];
            }
        }

        //Метод получения индекса ряда
        private int GetRowIndex(Key key)
        {
            if (key >= Key.D0 && key <= Key.D9) return 0;
            if (key >= Key.Q && key <= Key.P) return 1;
            if (key >= Key.A && key <= Key.L) return 2;
            if (key >= Key.Z && key <= Key.M) return 3;
            return 4;
        }

        //Старт программы
        private void BtnStart_Click(object sender, RoutedEventArgs e)
        {
            //Обновление кнопок и статуса
            isSessionActive = true;
            btnStart.IsEnabled = false;
            btnStop.IsEnabled = true;

            //СБрос счетчиков
            currentIndex = 0;
            correctChars = 0;
            errors = 0;
            sessionStart = DateTime.Now;

            //Генерация рандомного текста
            int length = (int)slDifficulty.Value;
            targetText = GenerateRandomText(length, cbCaseSensitive.IsChecked == true);
            tbTargetText.Text = targetText;
        }

        //Метод генерации текста
        private string GenerateRandomText(int length, bool caseSensitive)
        {
            //Символы
            string chars = "abcdefghijklmnopqrstuvwxyz1234567890-=[]\\;',./";
            //Проверка включенного тумблера с регистром
            if (caseSensitive)
                chars += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

            var random = new Random();
            char[] result = new char[length];

            //Генерация
            for (int i = 0; i < length; i++)
                result[i] = chars[random.Next(chars.Length)];

            return new string(result);
        }

        private void UpdateStats()
        {
            tbFails.Text = errors.ToString(); //Ошибки

            //Вычисление скорости печати
            double minutes = (DateTime.Now - sessionStart).TotalMinutes;
            int speed = minutes > 0.01 ? (int)(correctChars / minutes) : 0;
            tbSpeed.Text = $"{speed} chars/min";
        }

        //Остановка программы по кнопке
        private void BtnStop_Click(object sender, RoutedEventArgs e) => EndSession();

        //Конец программы
        private void EndSession()
        {
            //Сброс значений
            isSessionActive = false;
            btnStart.IsEnabled = true;
            btnStop.IsEnabled = false;

            //Вывод статистики
            MessageBox.Show($"Тренировка завершена\n\nСкорость: {tbSpeed.Text}\nОшибок: {errors}",
                            "Результат", MessageBoxButton.OK, MessageBoxImage.Information);
        }
    }
}