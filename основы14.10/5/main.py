import random
import time

array = [random.randint(1, 100) for _ in range(20)]
target = int(input("Введите число для поиска: "))

sorted_asc = sorted(array)
sorted_desc = sorted(array, reverse=True)
found = target in array
evens_count = sum(1 for x in array if x % 2 == 0)

print("Исходный:", array)
print("По возрастанию:", sorted_asc)
print("По убыванию:", sorted_desc)
print("Найдено:" if found else "Не найдено")
print("Четных элементов:", evens_count)

large_array = [random.randint(1, 10000) for _ in range(1000)]
start = time.time()
large_array.sort()
end = time.time()
print(f"Время сортировки 1000 элементов: {end - start:.6f} сек")
