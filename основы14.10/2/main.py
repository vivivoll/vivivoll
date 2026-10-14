import random

array = [random.randint(-30, 30) for _ in range(15)]

sum_positive = sum(x for x in array if x > 0)
count_negative = sum(1 for x in array if x < 0)
min_element = min(array)
max_element = max(array)

print("Исходный массив:", array)
print(f"Сумма положительных элементов: {sum_positive}")
print(f"Количество отрицательных элементов: {count_negative}")
print(f"Минимальный элемент: {min_element}")
print(f"Максимальный элемент: {max_element}")
