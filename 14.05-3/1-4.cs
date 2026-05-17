using System;

namespace Shop

//1
{
    // Структура товара
    struct Article
    {
        public int Code;       // Код товара
        public string Name;    // Название товара
        public double Price;   // Цена товара
    }
}

//2

{
    // Структура клиента
    struct Client
    {
        public int Code;              // Код клиента
        public string FullName;       // ФИО
        public string Address;        // Адрес
        public string Phone;          // Телефон

        public int OrdersCount;       // Количество заказов
        public double TotalSum;       // Общая сумма заказов
    }
}

//3

{
    // Товар в заказе
    struct RequestItem
    {
        public Article Product;   // Товар
        public int Count;         // Количество
    }
}

//4

{
    // Структура заказа
    struct Request
    {
        public int Code;               // Код заказа
        public Client Client;          // Клиент
        public DateTime Date;          // Дата заказа

        public RequestItem[] Items;    // Список товаров

        // Вычисляемое свойство суммы заказа
        public double Sum
        {
            get
            {
                double total = 0;

                for (int i = 0; i < Items.Length; i++)
                {
                    total += Items[i].Product.Price * Items[i].Count;
                }

                return total;
            }
        }
    }
}