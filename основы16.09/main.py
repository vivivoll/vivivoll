#1
"""
a = int(input("Введите первое число: "))
b = int(input("Введите второе число: "))

if(a > b):
    print(f"{a} больше {b}")
elif(b > a):
    print(f"{b} больше {a}")
elif(a == b):
    print(f"Оба числа равные")
else:
    print("Неккоректный ввод")
"""

#2
"""
import math

a = int(input("Введите значение a: "))
b = int(input("Введите значение b: "))
c = int(input("Введите значение c: "))

d = b**2 - 4 * a * c

if (d > 0):
    x_1 = (-b + math.sqrt(d)) / (2 * a)  
    x_2 = (-b - math.sqrt(d)) / (2 * a)
    print(f"x_1 = {x_1}, x_2 = {x_2}")
elif (d == 0):
    x = (-b) / (2 * a)
    print(f"x = {x}")
elif (d < 0):
    print(f"Нету решения")
"""

#3
"""
year = int(input("Введите год: "))

if (year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)):
    print(f"Год високосный")
else:
    print(f"Год невисокосный")
"""

#4
"""
n = int(input("Введите номер месяца: "))
if (n == 1):
    print(f"Месяц: Январь \n Кол-во дней: 31")
elif (n == 2):
    print(f"Месяц: Февраль \n Кол-во дней: 28")
elif (n == 3):
    print(f"Месяц: Март \n Кол-во дней: 31")
elif (n == 4):
    print(f"Месяц: Апрель \n Кол-во дней: 30")
elif (n == 5):
    print(f"Месяц: Май \n Кол-во дней: 31")
elif (n == 6):
    print(f"Месяц: Июнь \n Кол-во дней: 30")
elif (n == 7):
    print(f"Месяц: Июль \n Кол-во дней: 31")
elif (n == 8):
    print(f"Месяц: Август \n Кол-во дней: 31")
elif (n == 9):
    print(f"Месяц: Сентябрь \n Кол-во дней: 30")
elif (n == 10):
    print(f"Месяц: Октябрь \n Кол-во дней: 31")
elif (n == 11):
    print(f"Месяц: Ноябрь \n Кол-во дней: 30")
elif (n == 12):
    print(f"Месяц: Декабрь \n Кол-во дней: 31")
else:
    print(f"Неккоректный ввод")
"""

#5
"""
x = int(input("Введите первое число: "))
y = int(input("Введите второе число: "))
a = int(input("Выберите действие: 1.+   2.-   3.*   4./: "))

if (a == 1):
    print(f"{x} + {y} = {x + y}")
elif (a == 2):
    print(f"{x} - {y} = {x - y}")
elif (a == 3):
    print(f"{x} * {y} = {x * y}")
elif (a == 4):
    print(f"{x} / {y} = {x / y}")
else:
    print(f"Неккоректный ввод")
"""

#6
"""
sum = int(input("Введите сумму покупки: "))

if(sum > 1000):
    total_sum = (sum * 0.9)
    print(f"Итоговая сумма: {sum + total_sum}")
elif(sum > 500):
    total_sum = sum * 0.8
    print(f"Итоговая сумма: {sum + total_sum}")
else:
    print(f"Итоговая сумма: {sum}")
"""

#7
"""
x = int(input("Введите x: "))
y = int(input("Введите y: "))

if (x > 0 and y > 0):
    print("1 четверть")
elif (x < 0 and y > 0):
    print("2 четверть")
elif (x < 0 and y < 0):
    print("3 четверть")
elif (x > 0 and y < 0):
    print("4 четверть")
else:
    print("Неккоректный ввод")
"""

#8
"""
sum = int(input("Введите сумму вклада: "))
times = int(input("Введите срок в месяцах: "))

if (times < 6):
    total_sum = sum + (sum * 0.05)
    print(f"Итоговая сумма: {total_sum}")
elif (times >= 6 and times < 12):
    total_sum = sum + (sum * 0.07)
    print(f"Итоговая сумма: {total_sum}")
elif (times >= 12):
    total_sum = sum + (sum * 0.1)
    print(f"Итоговая сумма: {total_sum}")
else:
    print("Неккоректный ввод")
"""
