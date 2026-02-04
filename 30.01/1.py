class LibraryItem:
    def __init__(self, title: str, author: str, year: int):
        
        #защищенные атрибуты: уровня 1
        self._title = title    #название
        self._author = author  #автор
        self._year = year      #год издания

        #приватные атрибуты: уровня 2
        self.__item_id = self.__generate_item_id()
        self.__is_checked_out = False  #состояние выдачи книги

    #ПРИВАТНЫЕ МЕТОДЫ 
    
    #приватный метод генерации случайного id
    def __generate_item_id(self) -> str:  
        import random
        return f"{random.randint(100, 999)}"  
    
    #ГЕТТЕРЫ

    def get_title(self) -> str:
        return self._title

    def get_author(self) -> str:
        return self._author
    
    def get_year(self) -> int:
        return self._year
    
    def get_is_checked_out(self) -> bool:
        return self.__is_checked_out  
    
    def get_item_id(self) -> str:
        return self.__item_id
    
    #СЕТТЕРЫ
    
    def set_is_checked_out(self, value: bool):
        if value in [True, False]:  #проверка на значение true или false
            self.__is_checked_out = value
        else:
            print("Ошибка: значение должно быть True или False")


class Book(LibraryItem):
    def __init__(self, title: str, author: str, year: int, genre: str, page_count: int):
        #вызываем конструктор родительского класса
        super().__init__(title, author, year)
        
        #новые атрибуты
        self.genre = genre                     #публичный (жанр)
        self.__page_count = page_count         #приватный (количество страниц)
        
        #проверяем количество страниц при создании
        self.__validate_page_count()
    
    #ПРИВАТНЫЕ МЕТОДЫ
    
    def __validate_page_count(self):
        #проверка что количество страниц не меньше 1
        if self.__page_count < 1:
            print(f"Ошибка: количество страниц не может быть меньше 1. Установлено значение 1.")
            self.__page_count = 1
    
    #ГЕТТЕРЫ
    
    def get_page_count(self) -> int:
        return self.__page_count
    
    def get_genre(self) -> str:
        return self.genre
   
    #СЕТТЕРЫ
    
    def set_page_count(self, page_count: int):
        if page_count < 1:
            print(f"Ошибка!")
            return 
        self.__page_count = page_count
        print(f"Количество страниц успешно изменено на {page_count}")

#класс magazine - наследник libraryItem
class Magazine(LibraryItem):
    def __init__(self, title: str, author: str, year: int, issue_number: int):
        #конструктор родительского класса
        super().__init__(title, author, year)
        
        self._issue_number = issue_number  #защищенный атрибут (номер выпуска)
    
    #ГЕТТЕРЫ
    
    def get_issue_number(self) -> int:
        return self._issue_number
    
    #ДОПОЛНИТЕЛЬНЫЕ МЕТОДЫ
    
    def get_magazine_info(self) -> str:
        #получение информации о журнале
        base_info = f"Журнал: {self.get_title()}, Выпуск №{self._issue_number}"
        author_info = f", Издатель: {self.get_author()}"
        year_info = f", Год выпуска: {self.get_year()}"
        status_info = f", Статус: {'Выдан' if self.get_is_checked_out() else 'В наличии'}"
        
        return base_info + author_info + year_info + status_info
    
#класс DVD - наследник libraryItem
class DVD(LibraryItem):
    def __init__(self, title: str, author: str, year: int, duration: int, rating: str):
        #Конструктор родительского класса
        super().__init__(title, author, year)
        
        
        self.__duration = 0      #приватный(продолжительность в минутах)
        self.__rating = ""       #приватный(возрастной рейтинг)
        
        self.set_duration(duration)
        self.set_rating(rating)
    
    #ГЕТТЕРЫ
    
    def get_duration(self) -> int:
        return self.__duration
    
    def get_rating(self) -> str:
        return self.__rating
    
    #СЕТТЕРЫ
    
    def set_duration(self, duration: int):
        if duration < 1:
            print(f"Ошибка!")
            self.__duration = 1
        elif duration > 300:
            print(f"Ошибка!")
            self.__duration = 300
        else:
            self.__duration = duration
    
    def set_rating(self, rating: str):
        valid_ratings = ["G", "PG", "PG-13", "R", "NC-17"]
        if rating.upper() in valid_ratings:
            self.__rating = rating.upper()
        else:
            print(f"Ошибка!")
            self.__rating = "PG"