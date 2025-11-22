import timeit #Импорт библиотеки

def factorial(n): #Функция вычисления факториала
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)

n_values = [10, 20, 30] #Заданные n
number_of_runs = 10000 #Кол-во повторений

for n in n_values: #Цикл с замерами значений и времени
    time_taken = timeit.timeit(lambda: factorial(n), number=number_of_runs)  #Выполняет функцию и замеряет время
    print(f"{n} - {time_taken:.6f} сек") #Выводит время при определенном значении n 