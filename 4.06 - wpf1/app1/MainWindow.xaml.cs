using System;
using System.Text;
using System.Windows;
using System.Xml;

namespace WpfApp1
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        //Метод создания XMl
        private void CreateXml_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                XmlTextWriter writer = new XmlTextWriter("orders.xml", Encoding.UTF8);
                writer.Formatting = Formatting.Indented;    //Отступы

                writer.WriteStartDocument();    //Начало документа
                writer.WriteStartElement("Orders"); //Корневой тег

                //Первый заказ
                writer.WriteStartElement("Order");
                writer.WriteAttributeString("id", "1");
                writer.WriteElementString("customer", "Иван Иванов");
                writer.WriteStartElement("items");
                WriteItem(writer, "Ноутбук", "80000", "1");
                WriteItem(writer, "Мышь", "1200", "2");
                writer.WriteEndElement(); //items
                writer.WriteEndElement(); //Order

                // Второй заказ
                writer.WriteStartElement("Order");
                writer.WriteAttributeString("id", "2");
                writer.WriteElementString("customer", "Мария Сидорова");
                writer.WriteStartElement("items");
                WriteItem(writer, "Клавиатура", "3500", "1");
                writer.WriteEndElement(); //items
                writer.WriteEndElement(); //Order

                writer.WriteEndElement(); //Orders
                writer.WriteEndDocument();
                writer.Close();

                tbResult.Text = "Файл orders.xml создан";
            }
            catch (Exception ex)
            {
                tbResult.Text = "Ошибка: " + ex.Message;
            }
        }

        private void WriteItem(XmlTextWriter w, string name, string price, string qty)
        {
            w.WriteStartElement("item");
            w.WriteElementString("name", name);
            w.WriteElementString("price", price);
            w.WriteElementString("quantity", qty);
            w.WriteEndElement();
        }

        //Метод чтения через XmlDocument 
        private void ReadDocument_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                XmlDocument doc = new XmlDocument();    //Создание    
                doc.Load("orders.xml"); //Загрузка

                StringBuilder sb = new StringBuilder("Результат XmlDocument\n\n");

                XmlNodeList orders = doc.GetElementsByTagName("Order"); //Поиск тегов в разделе

                //Вывод через массив всех заказа и клиента
                foreach (XmlNode order in orders)
                {
                    sb.AppendLine($"Заказ №{order.Attributes["id"].Value}");    
                    sb.AppendLine($"Клиент: {order["customer"].InnerText}");

                    XmlNodeList items = order.SelectNodes("items/item");    //Поиск товаров в заказе
                    //Вывод товаров в заказе
                    foreach (XmlNode item in items)
                    {
                        sb.AppendLine($" - {item["name"].InnerText} | {item["quantity"].InnerText} | {item["price"].InnerText} ");
                    }
                }
                tbResult.Text = sb.ToString(); //вывод
            }
            catch (Exception ex)
            {
                tbResult.Text = "Ошибка:\n" + ex.Message;
            }
        }

        //Метод чтения через XmlTextReader 
        private void ReadReader_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                XmlTextReader reader = new XmlTextReader("orders.xml");
                reader.WhitespaceHandling = WhitespaceHandling.None;

                StringBuilder sb = new StringBuilder("Результат XmlTextReader\n\n");

                //Чтение потоком (по одному элементу)
                while (reader.Read())
                {
                    //Если тег открытый
                    if (reader.NodeType == XmlNodeType.Element)
                    {
                        if (reader.Name == "Order")
                        {
                            sb.AppendLine($"Заказ №{reader.GetAttribute("id")}");
                        }
                        else if (reader.Name == "customer")
                        {
                            reader.Read();
                            sb.AppendLine($"Клиент: {reader.Value}");
                        }
                        else if (reader.Name == "item")
                        {

                        }
                        else if (reader.Name == "name" || reader.Name == "price" || reader.Name == "quantity")
                        {
                            reader.Read();
                            sb.Append($"{reader.Name}: {reader.Value}   ");
                        }
                    }
                }
                reader.Close();
                tbResult.Text = sb.ToString(); //вывод
            }
            catch (Exception ex)
            {
                tbResult.Text = "Ошибка :\n" + ex.Message;
            }
        }
    }
}