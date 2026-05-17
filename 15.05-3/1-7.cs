using System;
using System.Numerics;

namespace ConsoleNew
{
    class Programs
    {
        enum ArticleType //Перечисление товара
        {
            Food,
            Books,
            Toys,
        }

        struct Article //Структура товара
        {
            public int code; //код товара
            public string name; //название товара
            public double price; //цена товара
            public ArticleType Type; //Тип товара
        }

        enum ClientType //Перечесление клиентов
        {
            Normal,
            Important,
        }

        struct Client //Структура клиента
        {
            public ClientType Type; //Тип клиента
            public int code; //код товара
            public string fullName; //ФИО
            public string address; //адрес
            public string phone; //телефон
            public int spisokRequest; //количество заказов осуществленных клиентом
            public int totalCountRequest; //общая сумма заказов клиента
        }

        struct RequestItem //Структура товара
        {
            public Article article; //товар
            public int count_article; //количество единиц товара
        }

        enum PayType //Перечисление оплаты
        {
            Card,
            Cash,
        }

        struct Request //Структура заказа
        {
            public PayType Type;
            public int code_requestItem; //код заказа
            public Client client; //клиент
            public string date_request; //дата заказа
            public RequestItem[] items; //перечень заказанных товаров
            public double sum_request //сумма заказа (вычисляемое свойвтво)
            {
                get
                {
                    //сумма
                    double total = 0;
                    //цена * количество
                    foreach (RequestItem item in items)
                    {
                        total += item.article.price * item.count_article;
                    }
                    return total;
                }
            }
        }

        static void Main(string[] args)
        {
            //Структура товара
            Article article = new Article
            {
                code = 133,
                name = "ПК",
                price = 50000,
            };
            Console.WriteLine("Структура товара");
            Console.WriteLine("Код: " + article.code);
            Console.WriteLine("Название: " + article.name);
            Console.WriteLine("Цена: " + article.price);
            Console.WriteLine("");

            //Структура клиента
            Client client_1 = new Client
            {
                code = 455,
                fullName = "Иванов Иван Иванович",
                address = "Ленина 123",
                phone = "88005553535",
                spisokRequest = 2,
                totalCountRequest = 13,
            };
            Console.WriteLine("Структура клиента");
            Console.WriteLine("Код: " + client_1.code);
            Console.WriteLine("ФИО: " + client_1.fullName);
            Console.WriteLine("Телефон: " + client_1.phone);
            Console.WriteLine("Кол-во заказов: " + client_1.spisokRequest);
            Console.WriteLine("Общая сумма заказов: " + client_1.totalCountRequest);
            Console.WriteLine("");

            //Структура товара
            RequestItem requestItem_1 = new RequestItem { article = article, count_article = 5 };
            Console.WriteLine("Структура товара: ");
            Console.WriteLine("Товар: " + requestItem_1.article.name);
            Console.WriteLine("Кол-во товаров: " + requestItem_1.count_article);
            Console.WriteLine("");

            //Структура заказа
            Request request_1 = new Request
            {
                code_requestItem = 6,
                client = client_1,
                date_request = "23.03.2026",
                items = new RequestItem[] { requestItem_1 },
                //sum_request
            };
            Console.WriteLine("Структура заказа");
            Console.WriteLine("Код: " + request_1.code_requestItem);
            Console.WriteLine("Клиент: " + request_1.client.fullName);
            Console.WriteLine("Дата заказа: " + request_1.date_request);
            Console.WriteLine("Перечень заказанных товаров:");
            foreach (RequestItem item in request_1.items)
            {
                Console.WriteLine(item.count_article);
            }
            Console.WriteLine("Сумма заказа: " + request_1.sum_request);
        }
    }
}

