def gas_station(dis, gas):
    # dis-расстояние
    # gas-ход с полным баком

    n=len(dis)
    fuel=gas
    stops=[]

    # заправка в питере
    coord=[0]
    for d in dis:
        coord.append(coord[-1] + d)

    print("=" * 60)
    print("Маршрут Петербург - Москва")
    print("=" * 60)
    print(f"Общее расстояние:{coord[-1]}км")
    print(f"Запас хода на полном баке:{gas}км")
    print("\nКоординаты заправок от Петербурга:")
    for i, c in enumerate(coord):
        if i==0:
            print(f"  Петербург:{c}км")
        elif i==len(coord)-1:
            print(f"  Москва:{c}км")
        else:
            print(f"  Заправка {i}:{c}км")

    print("\n" + "=" * 60)
    print("Начало поездки из СПБ до МСК")
    print("=" * 60)

    # модель поездки
    pos=0  # координата в км от питера
    i=0  # id заправки

    while i<n:
        # расстояние до след. точки
        to_next = dis[i]

        print(f"\nПозиция:{pos}км")
        print(f"До следующей точки:{to_next}км")
        print(f"Топлива:{fuel}км")

        if to_next > fuel:
            print(f"Мало топлива")

            # заправка
            if pos>0:  # если на заправке
                stops.append(i)  #id заправки
                fuel=gas
                print(f"Заправляемся на заправке №{i}")
                print(f"Бак заполнен до {fuel} км")
            else:
                # в питере уже заправились
                print("Уже заправлены в Петербурге")
                # проверяем маршрут
                if to_next > gas:
                    return "Маршрут недоступен! Расстояние до заправки,меньше вашего хода"
        fuel -= to_next
        pos += to_next
        i += 1

    print("\n" + "=" * 60)
    print("Приехали в Москву")
    print("=" * 60)

    return stops


# вывод
dis=[200, 150, 300, 250, 100]
gas=400

result = gas_station(dis, gas)
print(f"\nНужно заправиться на заправках: {[x + 1 for x in result]} (нумерация с 1)")
print(f"Всего заправок: {len(result)}")

#2 задание
def greedy_meetings(meetings):
    sorted_meet=sorted(meetings, key=lambda x: x[1])

    selected=[]
    last_end=-1

    for start, end in sorted_meet:
        if start >= last_end:
            selected.append((start, end))
            last_end = end

    return selected


#Пример
meetings=[(8, 10), (11, 13), (10, 12), (13, 14), (13, 15)]
print("\nЭвристика: выбор заседаний")
print("Все заседания: ", meetings)
print("Макс. можно посетить: ", greedy_meetings(meetings))

