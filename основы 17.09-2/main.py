import math

# 1

x0 = -1.5
xk = 3.5
dx = 0.5
a = -1.25
b = -1.5
c = 0.75

x = x0

while x <= xk + dx / 2:
    value = (a ** 3) * x

    if x == 0 or value < 0:
        print(f"x = {x:.2f}, y = не определено")
    else:
        y = (10 ** -2 * b * c) / x + math.cos(math.sqrt(value))
        print(f"x = {x:.2f}, y = {y:.4f}")

    x += dx

# 2
"""
x0 = 5.3
xk = 10.3
dx = 0.25
a = 1.35
b = -6.25

x = x0

while x <= xk + dx / 2:
    y = a * x ** 3 + math.cos(x ** 3 - b) ** 2
    print(f"x = {x:.2f}, y = {y:.4f}")

    x += dx
"""

# 3
"""
x0 = -0.75
xk = -2.05
dx = -0.2

x = x0

while x >= xk + dx / 2:
    y = 9 * x ** 4 + math.sin(57.2 + x)
    print(f"x = {x:.2f}, y = {y:.4f}")

    x += dx
"""

# 4
"""
x0 = -0.73
xk = -1.73
dx = -0.1
b = -2

x = x0

while x >= xk + dx / 2:
    denominator = abs(b ** 3 - x ** 3) ** 1.5

    if x == b or denominator == 0:
        print(f"x = {x:.2f}, y = не определено")
    else:
        y = (
            abs(x - b) ** 0.5 / denominator
            + math.log(abs(x - b))
        )
        print(f"x = {x:.2f}, y = {y:.4f}")

    x += dx
"""

# 5
"""
x0 = 1.23
xk = -2.4
dx = -0.3
b = 12.6

x = x0

while x >= xk + dx / 2:
    if x == 0:
        print(f"x = {x:.2f}, y = не определено")
    else:
        y = 15.28 * abs(x) ** (-1.5) + math.cos(
            math.log(abs(x)) + b
        )
        print(f"x = {x:.2f}, y = {y:.4f}")

    x += dx
"""