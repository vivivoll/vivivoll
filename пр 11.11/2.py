import math

a = int(input("Введите a: "))
b = int(input("Введите b: "))
c = int(input("Введите c: "))

#Проверка на треугольник и тип треугольника
if a == 0 or b == 0 or c == 0 or a+b<=c or a+c<=b or b+c<=a:
    print ("Неверно!")
else:
    #Большая сторона = A
    if a > b and a > c:
        if a**2 == c**2 + b**2:
            print("Прямоугольный")
        elif a**2 < c **2 + b**2:
            print("Остроугольный")
        elif a**2 > c **2 + b**2:
            print("Тупоугольный")

    #Большая сторона = B
    elif b > a and b > c:
        if b**2 == c**2 + a**2:
            print("Прямоугольный")
        elif b**2 < c **2 + a**2:
            print("Остроугольный")
        elif b**2 > c **2 + a**2:
            print("Тупоугольный")

    #Большая сторона = C
    elif c > a and c > b:
        if c**2 == a**2 + b**2:
            print("Прямоугольный")
        elif c**2 < a **2 + b**2:
            print("Остроугольный")
        elif c**2 > a **2 + b**2:
            print("Тупоугольный")

#Равносторонний
if a == b == c:
    print("Площадь: ", (math.sqrt(3) / 4) * a**2)

#Равнобедренный
elif a == b or a == c or b == c:
    if a == b:
        h = math.sqrt(a**2 - (c/2)**2)
        print("Площадь: ", (c*h) / 2)

    elif a == c:
        h = math.sqrt(a**2 - (b/2)**2)
        print("Площадь: ", (b*h) / 2)
        
    elif b == c:
        h = math.sqrt(b**2 - (a/2)**2)
        print("Площадь: ", (a*h) / 2)

#Разносторонний
else:
    poluperimetr = (a + b + c) / 2
    print("Площадь: ", (math.sqrt(poluperimetr * (poluperimetr - a) * (poluperimetr - b) * (poluperimetr - c))))
    



