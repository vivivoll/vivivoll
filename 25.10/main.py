# 1
"""
with open("books.txt", "w", encoding="utf-8") as f:
    f.write("Пушкин;Капитанская дочка;1836;350\n")
    f.write("Глуховский;Метро 2035;2015;600\n")
    f.write("Иванов;Тобол;2017;750\n")
    f.write("Пелевин;Тайные виды на гору Фудзи;2018;900\n")
    f.write("Кинг;Институт;2019;850\n")
    f.write("Достоевский;Идиот;1869;400\n")

print("Книги, изданные после 2015 года:")
with open("books.txt", "r", encoding="utf-8") as f:
    for line in f:
        line = line.strip()
        if not line:
            continue
        author, title, year, price = line.split(";")
        if int(year) > 2015:
            print(f"Автор: {author}, Название: '{title}', Год: {year}, Цена: {price} руб.")
"""

# 2
"""
with open("products_task2.txt", "w", encoding="utf-8") as f:
    f.write("Ноутбук;50000;2\n")
    f.write("Мышь;1500;10\n")
    f.write("Монитор;15000;4\n")
    f.write("Клавиатура;3000;7\n")
    f.write("Наушники;5500;5\n")

total_price = 0
count = 0
with open("products_task2.txt", "r", encoding="utf-8") as f:
    for line in f:
        line = line.strip()
        if not line:
            continue
        name, price, qty = line.split(";")
        total_price += float(price)
        count += 1

avg_price = total_price / count if count > 0 else 0
print(f"Средняя цена товаров: {avg_price:.2f} руб.\n")

print("Товары дороже средней цены:")
with open("products_task2.txt", "r", encoding="utf-8") as f:
    for line in f:
        line = line.strip()
        if not line:
            continue
        name, price, qty = line.split(";")
        if float(price) > avg_price:
            print(f"Товар: {name}, Цена: {price} руб., Количество: {qty}")
"""

# 3
"""
with open("employees.txt", "w", encoding="utf-8") as f:
    f.write("Иванов;Инженер;45000\n")
    f.write("Петров;Старший инженер;65000\n")
    f.write("Сидоров;Техник;35000\n")
    f.write("Смирнов;Руководитель отдела;120000\n")
    f.write("Кузнецов;Программист;95000\n")
    f.write("Попов;Стажер;25000\n")

print("Сотрудники с окладом выше 50 000:")
with open("employees.txt", "r", encoding="utf-8") as f:
    for line in f:
        line = line.strip()
        if not line:
            continue
        last_name, position, salary = line.split(";")
        if float(salary) > 50000:
            print(f"Фамилия: {last_name}, Должность: {position}, Оклад: {salary} руб.")
"""

# 4
"""
with open("cars.txt", "w", encoding="utf-8") as f:
    f.write("Toyota Camry;2015;120000\n")
    f.write("Lada Granta;2018;80000\n")
    f.write("Mercedes-Benz E-Class;2010;250000\n")
    f.write("BMW 5 Series;2012;190000\n")
    f.write("Volkswagen Golf;2005;310000\n")

oldest_car = None
min_year = 9999

with open("cars.txt", "r", encoding="utf-8") as f:
    for line in f:
        line = line.strip()
        if not line:
            continue
        brand, year, mileage = line.split(";")
        year_int = int(year)
        if year_int < min_year:
            min_year = year_int
            oldest_car = (brand, year, mileage)

if oldest_car:
    print(f"Самый старый автомобиль: {oldest_car[0]} ({oldest_car[1]} г.в., пробег: {oldest_car[2]} км)")
"""

# 5
"""
with open("students.txt", "w", encoding="utf-8") as f:
    f.write("Алексеев;ИП-21;4.8\n")
    f.write("Борисов;ИП-21;3.9\n")
    f.write("Васильев;ИП-22;4.2\n")
    f.write("Григорьев;ИП-22;4.5\n")
    f.write("Дмитриев;ИП-21;5.0\n")
    f.write("Егоров;ИП-22;3.6\n")

print("Студенты-отличники (балл >= 4.5):")
with open("students.txt", "r", encoding="utf-8") as f_in, \
     open("excellent_students.txt", "w", encoding="utf-8") as f_out:
     
    for line in f_in:
        line = line.strip()
        if not line:
            continue
        last_name, group, gpa = line.split(";")
        if float(gpa) >= 4.5:
            print(f"Фамилия: {last_name}, Группа: {group}, Средний балл: {gpa}")
            f_out.write(f"{last_name};{group};{gpa}\n")
"""