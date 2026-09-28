import math

def f(x):
    return x ** 2

# Задание 1
x = float(input("Введите x: "))
y = float(input("Введите y: "))

if x * y > 0:
    a = (f(x) + y) ** 2 - math.sqrt(f(x) * y)
elif x * y < 0:
    a = (f(x) + y) ** 2 + math.sqrt(abs(f(x) * y))
else:
    a = (f(x) + y) ** 2 + 1

print("Ответ =", a)

# Задание 2
"""
x = float(input("Введите x: "))
y = float(input("Введите y: "))

if y == 0:
    b = 0
elif x == 0:
    b = (f(x) ** 2 + y) ** 3
elif x / y > 0:
    b = math.log(abs(f(x))) + (f(x) ** 2 + y) ** 3
else:
    b = math.log(abs(f(x) / y)) + (f(x) + y) ** 3

print("Ответ =", b)
"""

# Задание 3
"""
x = float(input("Введите x: "))
a = float(input("Введите a: "))

if 1 < abs(x) < 3:
    q = ((a * x ** 2 + 2) / (x ** 2 + 1)) * f(x)
elif abs(x) >= 3:
    q = a ** 2 + f(x)
else:
    q = a * x * f(x) / (x + 2)

print("Ответ =", q)
"""

# Задание 4
"""
x = float(input("Введите x: "))
b = float(input("Введите b: "))

if 1 < x * b < 10:
    s = math.exp(f(x))
elif 12 < x * b < 40:
    s = math.sqrt(abs(f(x) + 4 * b))
else:
    s = b * f(x) * x ** 2

print("Ответ =", s)
"""

# Задание 5
"""
x = float(input("Введите x: "))
y = float(input("Введите y: "))
z = float(input("Введите z: "))

m = max(f(x), y, z) / min(f(x), y) + 5

print("Ответ =", m)
"""