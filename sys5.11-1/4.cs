using System;

class Program
{
    static void Main()
    {
        //создаем новый домен приложения
        var domain = AppDomain.CreateDomain("NewDomain");

        //смотрим как он называется
        Console.WriteLine($"новый домен: {domain.FriendlyName}");

        //выгружаем его
        AppDomain.Unload(domain);
        Console.WriteLine("домен выгружен");
    }
}