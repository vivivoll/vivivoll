import statistics

grades = [5, 4, 4, 3, 5, 5, 4, 2, 3, 5, 4, 4, 5, 3, 4]

mean_val = statistics.mean(grades)
median_val = statistics.median(grades)
mode_val = statistics.mode(grades)
stdev_val = statistics.stdev(grades)

print(f"Среднее арифметическое: {mean_val:.2f}")
print(f"Медиана: {median_val}")
print(f"Мода: {mode_val}")
print(f"Стандартное отклонение: {stdev_val:.2f}")
