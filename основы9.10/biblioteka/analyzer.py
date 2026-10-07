import mystring

text = input("Введите текст: ")

print("Слов в тексте:", mystring.count_words(text))
print("Перевёрнутый текст:", mystring.reverse(text))

sub = input("Какую подстроку найти? ")
pos = mystring.find_substring(text, sub)
if pos == -1:
    print("Подстрока не найдена.")
else:
    print("Подстрока найдена на позиции", pos)

print("В верхнем регистре:", mystring.to_upper(text))
print("В нижнем регистре:", mystring.to_lower(text))