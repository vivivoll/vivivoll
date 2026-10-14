import math

a = 4
b = 9
c = -16

mean_arithmetic = (a + b + c) / 3
mean_geometric = math.pow(abs(a * b * c), 1/3)  
max_abs = max(abs(a), abs(b), abs(c))

print(f"среднее арифм. = {mean_arithmetic}")
print(f"среднее геом. = {mean_geometric:.0f}")
print(f"макс. по модулю = {max_abs}")
