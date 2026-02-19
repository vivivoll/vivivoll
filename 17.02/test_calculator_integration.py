import unittest #Импорт для тестов
from calculator_with_history import CalculatorWithHistory #импорт файлов

#Тестовый класс
class TestCalculator(unittest.TestCase):
    #Проверка на правильные действия и сохранение истории
    def setUp(self):
        #Новый объект для каждого теста
        self.calc = CalculatorWithHistory()

    #Проверка сложения
    def test_addition_saves_to_history(self):
        #Тест 5 + 3
        result = self.calc.perform_addition(5, 3)

        #Ожидаем результат
        self.assertEqual(result, 8)

        #Текущая история
        history = self.calc.get_operation_history()
        #Проверка: есть ли одна запись
        self.assertEqual(len(history), 1)
        #Проверка содержания записи
        self.assertEqual(history[0], "5 + 3 -> 8")

    #Проверка вычитания
    def test_subtraction_saves_to_history(self):
        #Тест 10 - 4
        result = self.calc.perform_subtraction(10, 4)

        #Ожидаем результат
        self.assertEqual(result, 6)

        #Текущая история
        history = self.calc.get_operation_history()
        #Проверка: есть ли одна запись
        self.assertEqual(len(history), 1)
        #Проверка содержания записи
        self.assertEqual(history[0], "10 - 4 -> 6")

    #Проверка нескольких операций
    def test_multiple_operations_history_order(self):
        #1+1
        self.calc.perform_addition(1, 1)
        #5*2
        self.calc.perform_subtraction(5, 2)

        #Получаем всю историю
        history = self.calc.get_operation_history()

        #Проверка что записи 2шт
        self.assertEqual(len(history), 2)
        #Проверка содержания первой записи
        self.assertEqual(history[0], "1 + 1 -> 2")
        #Проверка второй записи
        self.assertEqual(history[1], "5 - 2 -> 3")


if __name__ == '__main__':
    #Запуск тестов
    unittest.main()