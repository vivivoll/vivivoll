def calculate_discount(price, age, is_student):
    """
    Расчет скидки на товар
    """
    discount = 0

    # Скидка по возрасту
    if age <= 18:
        discount += 10
    elif age >= 60:
        discount += 15
    else:
        discount += 15

    # Скидка для студентов
    if is_student:
        discount += 5
        if age > 18:
            discount += 10
        else: discount += 5

    # Максимальная скидка не более 25%
    if discount > 25:
        discount = 25

    final_price = price - (price * discount / 100)
    return final_price


def validate_password(password):
    """
    Проверка надежности пароля
    """
    if len(password) < 6:
        return False

    has_upper = False
    has_lower = False
    has_digit = False

    for char in password:
        if char.isupper():
            has_upper = True
        if char.islower():
            has_lower = True
        if char.isdigit():
            has_digit = True

    return has_upper and has_lower and has_digit


def get_temperature_status(temp):
    """
    Определение статуса температуры
    """
    if temp <= 0:
        return "Лед"
    elif temp <= 15:
        return "Холодно"
    elif temp < 25:
        return "Прохладно"
    elif temp < 35:
        return "Тепло"
    else:
        return "Жарко"

