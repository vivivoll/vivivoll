#1
a = int(input("Первое: "))
b = int(input("Второе: "))

print("Сумма:", a + b)
print("Разность:", a - b)
print("Произведение:", a * b)
print("Частное:", a / b)

#2
a = int(input("Длина прямоугольника: "))
b = int(input("Ширина прямоугольника: "))

square = a * b
perimetr = (a*2) + (b*2)

print(f"Площадь: {square}")
print(f"Периметр: {perimetr}")

#3
a = int(input("a: "))
b = int(input("b: "))

a = a+b
b = a-b
a = a-b

print(f"a = {a}, b = {b}")

#4
start_second = int(input("Введите кол-во секунд: "))

hours = start_second // 3600
minute = (start_second % 3600) // 60
end_second = start_second % 60

print(f"{hours} часов, {minute} минут, {end_second} секунд")

#5
x = int(input("x: "))
y = int(input("y: "))

z = (x**2 + y**2) / (2*x*y) + (x-y) / (x+y)

print(f"z = {z}")