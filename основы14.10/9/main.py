import random
import datetime
import statistics
import json

start_date = datetime.date.today()
diary = []

for i in range(7):
    cur_date = start_date + datetime.timedelta(days=i)
    temp = random.randint(-20, 35)
    diary.append({"date": str(cur_date), "temp": temp})

temps = [x["temp"] for x in diary]
mean_t = statistics.mean(temps)
max_t = max(temps)
min_t = min(temps)

best_day = min(diary, key=lambda x: x["temp"])
worst_day = max(diary, key=lambda x: x["temp"])

print(f"Статистика: Средняя={mean_t:.1f}, Макс={max_t}, Мин={min_t}")

for d in diary:
    bars = "#" * (d["temp"] + 20)
    print(f"{d['date']}: {bars} ({d['temp']}°C)")

with open("weather.json", "w") as f:
    json.dump(diary, f)
