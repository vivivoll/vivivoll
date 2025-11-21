import math

a = int(input("Введите a: "))
b = int(input("Введите b: "))
c = int(input("Введите c: "))

#Проверка на треугольник
if a == 0 or b == 0 or c == 0 or a+b<=c or a+c<=b or b+c<=a:
    print ("Неверно!")

#Равносторонний
elif a == b == c:
    print("Равносторонний")
    print("Площадь: ", (math.sqrt(3) / 4) * a**2)

#Равнобедренный
elif a == b or a == c or b == c:
    if a == b:
        h = math.sqrt(a**2 - (c/2)**2)
        print("Равнобедренный")
        print("Площадь: ", (c*h) / 2)

    elif a == c:
        h = math.sqrt(a**2 - (b/2)**2)
        print("Равнобедренный")
        print("Площадь: ", (b*h) / 2)
        
    elif b == c:
        h = math.sqrt(b**2 - (a/2)**2)
        print("Равнобедренный")
        print("Площадь: ", (a*h) / 2)
    
#Разносторонний
else:
    poluperimetr = (a + b + c) / 2
    print("Разносторонний")
    print("Площадь: ", (math.sqrt(poluperimetr * (poluperimetr - a) * (poluperimetr - b) * (poluperimetr - c))))
    