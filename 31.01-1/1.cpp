#include <iostream>
#include <string>
using namespace std;

//структура
struct videoShop{
    string name_film; 
    string director; 
    string genre;    
    float rating;       
    int price_disk;         
};

//функция чтобы находить фильм по названию
void FindToFilmName(const videoShop film[], int size, const string &name_film){
    for(int i = 0; i < size; i++){
        //если фильм найден, выводим его
        if(film[i].name_film == name_film){
            cout << "Фильм найден: " << film[i].name_film << endl;
            cout << endl;
            return; 
        }
    }
    //если нет то
    cout << "Фильм не найден";
    cout << endl;
}

//функция чтобы искать фильм по жанру
void FindToFilmGenre(const videoShop film[], int size, const string &genre){
    //проходимся столько раз, сколько фильмов в массиве
    for(int i = 0; i < size; i++){
        //если есть жанр то выводим сообщение
        if(film[i].genre == genre){
            cout << "Фильм с жанром " << film[i].genre << " Найден" << endl;
            cout << "Фильм: " << film[i].name_film << endl;
            cout << endl;
            return;
        }
    }
    //иначе выводим о неуспешной операции
    cout << "Фильм не найден по введенному жанру";
    cout << endl;
}

//функция для поиска фильма по режиссеру
void FindToFilmDirector(const videoShop film[], int size, const string &director){
    //проходимся столько раз, сколько фильмов в массиве
    for(int i = 0; i < size; i++){
        //если найден фильм по режиссеру, то выводим фильм
        if(film[i].director == director){
            cout << "Фильм по режиссеру " << film[i].director << " найден" << endl;
            cout << "Фильм: " << film[i].name_film << endl; 
            cout << endl;
            return;
        }
    }
    //иначе сообщаем что не нашли
    cout << "Фильм по режиссеру не найден" << endl;
    cout << endl;
}

//функция для поиска самого популярного фильма в жанре
void FindToFilmPopularGenre(const videoShop film[], int size, const string &genre){
    //начальный максимальный рейтинг
    float max_rating = -1;
    //переменная чтобы передать название фильма для вывода
    int index = -1;
    //проходимся по нему столько раз, сколько всего фильмов в массиве
    for(int i = 0; i < size; i++){
        //если фильм по жанру найден и он больше макс.рейтинга
        if(film[i].genre == genre && film[i].rating > max_rating){
            max_rating = film[i].rating;
            index = i; 
        }
    }
    cout << "Фильм с максимальным рейтингом: " << max_rating << endl;
    cout << "Фильм: " << film[index].name_film << endl;
    cout << "Жанр: " << film[index].genre << endl;
    cout << endl;
    return;
}

//функция для вывода информации о всех фильмах
void ShowInfo(const videoShop film[], int size){
    //выводим информацию о фильмах столько, сколько фильмов в массиве
    for(int i = 0; i < size; i++){
        cout << "Название: " << film[i].name_film << endl;
        cout << "Режиссер: " << film[i].director << endl;
        cout << "Жанр: " << film[i].genre << endl;
        cout << "Рейтинг: " << film[i].rating << endl;
        cout << "Цена диска: " << film[i].price_disk << endl;
        cout << endl;
        return;
    }
}

//функция для добавления нового фильма в массив
void GetFilm(videoShop film[], int &size){
    cout << "Название: ";
    getline(cin, film[size].name_film);
    cout << "Режиссер: ";
    getline(cin, film[size].director);
    cout << "Жанр: ";
    getline(cin, film[size].genre);
    cout << "Рейтинг: ";
    cin >> film[size].rating;
    cout << "Цена диска: ";
    cin >> film[size].price_disk;
    cin.ignore();
    size ++;
    return;
}

int main(){
    setlocale(LC_ALL, "ru");

    videoShop film = {"Фильм 1", "Фильм 2", "Фильм 3", 8.2, 1000};
    //количество заполненных фильмов в массив
    int size = 1;

    //новый массив с 100 фильмами
    videoShop film_1[100];
    //объект с VideoShop c инициализацией
    film_1[0] = {"Фильм 1", "Фильм 2", "Фильм 3", 8.2, 1000};
    //количество заполненных фильмов в массив
    int size_1 = 1;

    //вызов функции для поиска фильма
    FindToFilmName(&film, 1, "Фильм 1");
    //вызов функции для поиска фильма по жанру
    FindToFilmGenre(&film, 1, "Фильм 3");
    //вызов функции для поиска фильма по режиссеру
    FindToFilmDirector(&film, 1, "Фильм 2");
    //вызов функции для поиска самого популярного фильма по жанру
    FindToFilmPopularGenre(&film, 1, "Фильм 3");
    //вызов функции для показа информации о фильмах
    ShowInfo(&film, 1);
    //вызов функции для добавления нового фильма в массив
    GetFilm(film_1, size_1);
    
    return 0;
}