contacts = []
def add_contact(name, phone, email):
    contacts.append({"name": name, "phone": phone, "email": email})
    print("Контакт добавлен.")

def delete_contact(name):
    for c in contacts:
        if c["name"] == name:
            contacts.remove(c)
            return True
    return False

def find_contact(name):
    for i in range(len(contacts)):
        if contacts[i]["name"] == name:
            return i
    return -1

def print_all():
    if len(contacts) == 0:
        print("Список пуст.")
        return
    for i in range(len(contacts)):
        c = contacts[i]
        print(f'{i + 1}) {c["name"]} | {c["phone"]} | {c["email"]}')

def show_menu():
    print()
    print("Записная книжка")
    print("1.Добавить контакт")
    print("2.Удалить контакт")
    print("3.Найти контакт")
    print("4.Показать все контакты")
    print("5.Сохранить в файл")
    print("6.Загрузить из файла")
    print("0.Выход")

def read_line(prompt):
    return input(prompt).strip()

def save_to_file(filename):
    try:
        f = open(filename, "w", encoding="utf-8")
        for c in contacts:
            f.write(c["name"] + "\n")
            f.write(c["phone"] + "\n")
            f.write(c["email"] + "\n")
        f.close()
        return True
    except:
        return False

def load_from_file(filename):
    try:
        f = open(filename, "r", encoding="utf-8")
    except:
        return False

    contacts.clear()
    lines = f.readlines()
    f.close()

    for i in range(len(lines)):
        lines[i] = lines[i].rstrip("\n")

    i = 0
    while i + 2 < len(lines):
        contacts.append({
            "name": lines[i],
            "phone": lines[i + 1],
            "email": lines[i + 2]
        })
        i += 3
    return True

def main():
    filename = "contacts.txt"

    while True:
        show_menu()
        choice = read_line("Выбор: ")

        if choice == "0":
            print("Пока!")
            break

        elif choice == "1":
            name = read_line("Имя: ")
            phone = read_line("Телефон: ")
            email = read_line("Email: ")
            add_contact(name, phone, email)

        elif choice == "2":
            name = read_line("Имя для удаления: ")
            if delete_contact(name):
                print("Удалено.")
            else:
                print("Контакт не найден.")

        elif choice == "3":
            name = read_line("Имя для поиска: ")
            i = find_contact(name)
            if i == -1:
                print("Контакт не найден.")
            else:
                c = contacts[i]
                print(f'{c["name"]} | {c["phone"]} | {c["email"]}')

        elif choice == "4":
            print_all()

        elif choice == "5":
            if save_to_file(filename):
                print("Сохранено в", filename)
            else:
                print("Ошибка сохранения.")

        elif choice == "6":
            if load_from_file(filename):
                print("Загружено. Контактов:", len(contacts))
            else:
                print("Файл не найден или ошибка чтения.")
        else:
            print("Неверный пункт меню.")

if __name__ == "__main__":
    main()