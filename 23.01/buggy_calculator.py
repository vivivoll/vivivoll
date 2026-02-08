"""
Тестируемое приложение "Калькулятор с багами"
Студент тестирует это приложение методами черного ящика
"""
import sys


def buggy_calculator():
    """
    Калькулятор с намеренными багами для тестирования
    Баги:
    1. Деление на 0 вызывает падение (необработанное исключение) - ИСПРАВЛЕНО
    2. Умножение 10 на 10 возвращает 1010 вместо 100 - ИСПРАВЛЕНО
    3. Вычитание из меньшего числа большего дает 0 - ИСПРАВЛЕНО
    4. Квадратный корень из отрицательного числа вызывает RuntimeError - ИСПРАВЛЕНО
    5. При вводе букв вместо цифр - бесконечный цикл - ИСПРАВЛЕНО
    """
    print("=" * 50)
    print("БАГАТЫЙ КАЛЬКУЛЯТОР (с багами)")
    print("=" * 50)
    print("Операции: +, -, *, /, sqrt, power")
    print("Для выхода введите 'exit'")
    print("=" * 50)

    while True:
        try:
            num1_input = input("\nВведите первое число: ")
            if num1_input.lower() == 'exit':
                break

            # ИСПРАВЛЕН 5 БАГ: Проверка на корректность ввода
            try:
                num1 = float(num1_input)
            except ValueError:
                print("ОШИБКА: Введите число, а не текст!")
                continue

            op = input("Введите операцию (+, -, *, /, sqrt, power): ")

            if op == 'sqrt':
                # ИСПРАВЛЕН 4 БАГ: Убрали RuntimeError
                if num1 < 0:
                    print("ОШИБКА: Квадратный корень из отрицательного числа!")
                    continue
                result = num1 ** 0.5
            else:
                num2 = float(input("Введите второе число: "))

                if op == '+':
                    result = num1 + num2
                elif op == '-':
                    # ИСПРАВЛЕН 3 БАГ: Правильная проверка
                    result = num1 - num2  
                elif op == '*':
                    # ИСПРАВЛЕН 2 БАГ: Убрана ошибка
                    result = num1 * num2 
                elif op == '/':
                    # ИСПРАВЛЕН 1 БАГ: Проверка деления на 0
                    if num2 == 0:
                        print("ОШИБКА: Деление на ноль!")
                        continue
                    result = num1 / num2
                elif op == 'power':
                    result = num1 ** num2
                else:
                    print("Неизвестная операция!")
                    continue

            print(f"Результат: {result}")

        except ZeroDivisionError:
            print("ОШИБКА: Деление на ноль!")
            # ИСПРАВЛЕНО: Убрано неправильное сообщение
            print("Введите другое второе число")
        except ValueError as e:
            print(f"ОШИБКА ввода: Введите число!")
            continue  # ИСПРАВЛЕН
        except Exception as e:
            print(f"Неизвестная ошибка: {e}")


if __name__ == "__main__":
    buggy_calculator()