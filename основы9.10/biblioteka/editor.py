import mystring

text = input("Введите строку: ")

while True:
    print()
    print("1. Показать перевёрнутую строку")
    print("2. Заменить подстроку")
    print("3. Верхний регистр")
    print("4. Нижний регистр")
    print("0. Выход")

    choice = input("Выбор: ").strip()

    if choice == "0":
        break
    elif choice == "1":
        print(mystring.reverse(text))
    elif choice == "2":
        old = input("Что заменить: ")
        new = input("На что заменить: ")
        text = mystring.replace_substring(text, old, new)
        print("Результат:", text)
    elif choice == "3":
        text = mystring.to_upper(text)
        print("Результат:", text)
    elif choice == "4":
        text = mystring.to_lower(text)
        print("Результат:", text)
    else:
        print("Неверный пункт.")