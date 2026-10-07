# 1. Модуль игрового поля
board = [" "] * 9


def create_board():
    global board
    board = [" "] * 9


def show_board():
    print()
    print(f" {board[0]} | {board[1]} | {board[2]} ")
    print("---+---+---")
    print(f" {board[3]} | {board[4]} | {board[5]} ")
    print("---+---+---")
    print(f" {board[6]} | {board[7]} | {board[8]} ")
    print()


def check_win():
    win_lines = [
        (0, 1, 2), (3, 4, 5), (6, 7, 8),  # строки
        (0, 3, 6), (1, 4, 7), (2, 5, 8),  # столбцы
        (0, 4, 8), (2, 4, 6)              # диагонали
    ]
    for a, b, c in win_lines:
        if board[a] != " " and board[a] == board[b] == board[c]:
            return board[a]
    return None


def is_full():
    return " " not in board


# 2. Модуль игроков
def make_move(player, pos):
    if pos < 0 or pos > 8:
        print("Неверная клетка. Введите 1-9.")
        return False
    if board[pos] != " ":
        print("Клетка занята.")
        return False
    board[pos] = player
    return True


def get_move(player):
    while True:
        s = input(f"Игрок {player}, ваш ход (1-9): ").strip()
        if not s.isdigit():
            print("Введите число от 1 до 9.")
            continue
        pos = int(s) - 1
        if make_move(player, pos):
            return


# 3. Модуль игры
def play_game():
    create_board()
    current = "X"

    while True:
        show_board()
        get_move(current)

        winner = check_win()
        if winner:
            show_board()
            print(f"Победил игрок {winner}!")
            return
        if is_full():
            show_board()
            print("Ничья!")
            return

        # смена игрока
        current = "O" if current == "X" else "X"


# 4. Главный модуль
def main():
    while True:
        print()
        print("=== Крестики-нолики ===")
        print("1. Начать игру")
        print("0. Выход")

        choice = input("Выбор: ").strip()

        if choice == "0":
            print("Пока!")
            break
        elif choice == "1":
            play_game()
        else:
            print("Неверный пункт.")


if __name__ == "__main__":
    main()