#1
RU_LOW = "йцукенгшщз"
RU_UP = RU_LOW.upper()
EN_LOW = "qwertyuiop"
EN_UP = EN_LOW.upper()

ALPHABETS = [RU_LOW, RU_UP, EN_LOW, EN_UP]

def shift_char(ch, k):
    for alpha in ALPHABETS:
        idx = alpha.find(ch)
        if idx != -1:
            new_idx = (idx + k) % len(alpha)
            return alpha[new_idx]
    return ch


def shift_text(text, k):
    return "".join(shift_char(c, k) for c in text)


def encrypt(text, key, k):
    step1 = shift_text(text, k)
    step2 = step1[::-1]
    chars = list(step2)
    for i in range(1, len(chars), 2):
        chars[i] = "#"
    step3 = "".join(chars)
    result = key + step3
    return result

def decrypt(enc, key, k):
    pos = enc.find(key)
    if pos != -1:
        enc = enc[:pos] + enc[pos + len(key):]

    chars = list(enc)
    for i in range(1, len(chars), 2):
        if chars[i] == "#":
            chars[i] = "?"
    restored = "".join(chars)

    reversed_back = restored[::-1]

    result = shift_text(reversed_back, -k)
    return result


if __name__ == "__main__":
    print("1 - зашифровать, 2 - расшифровать")
    mode = input("режим: ").strip()

    if mode == "1":
        text = input("сообщение: ")
        key = input("ключ: ")
        k = int(input("сдвиг K: "))
        print("зашифровано:", encrypt(text, key, k))
    else:
        enc = input("зашифрованная строка: ")
        key = input("ключ: ")
        k = int(input("сдвиг K: "))
        print("расшифровано:", decrypt(enc, key, k))
