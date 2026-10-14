import datetime

d, m, y = map(int, input("Введите день, месяц, год через пробел: ").split())
birthday = datetime.date(y, m, d)
today = datetime.date.today()

days_ru = ["понедельник", "вторник", "среда", "четверг", "пятница", "суббота", "воскресенье"]
weekday = days_ru[birthday.weekday()]

age = today.year - birthday.year - ((today.month, today.day) < (birthday.month, birthday.day))

next_birthday = datetime.date(today.year, birthday.month, birthday.day)
if next_birthday <= today:
    next_birthday = datetime.date(today.year + 1, birthday.month, birthday.day)

days_to_bd = (next_birthday - today).days

print(f"День недели: {weekday}")
print(f"Полных лет: {age}")
print(f"Дней до следующего ДР: {days_to_bd}")
