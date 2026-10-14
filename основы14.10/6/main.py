s = input("Введите строку: ")
sub = "г"

print("Длина:", len(s))
print("Верхний регистр:", s.upper())
print("Позиция подстроки:", s.find(sub))
print("Замена:", s.replace('а', '*'))
print("Реверс:", s[::-1])
