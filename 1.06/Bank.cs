using System;

namespace ConsoleNew
{
    //пользовательские исключения
    class InvalidAmountException : Exception
    {
        public InvalidAmountException(string message) : base(message) { }
    }

    class InsufficientFundsException : Exception
    {
        public InsufficientFundsException(string message) : base(message) { }
    }

    //банковский счет
    class BankAccount
    {
        public string AccountNumber { get; set; }
        public decimal Balance { get; set; }

        //конструктор
        public BankAccount()
        {
            AccountNumber = Guid.NewGuid().ToString().Substring(0, 8).ToUpper();
            Balance = 0;
        }

        //метод взноса депозита
        public void Deposit(decimal amount)
        {
            if (amount <= 0)
                throw new InvalidAmountException("Сумма пополнения должна быть положительной");

            Balance += amount;
        }

        //метод условий исключения
        public void Withdraw(decimal amount)
        {
            if (amount <= 0)
                throw new InvalidAmountException("Сумма снятия должна быть положительной");

            if (amount > Balance)
                throw new InsufficientFundsException("Недостаточно средств на счете");

            Balance -= amount;
        }
        //метод вывода
        public void ShowBalance()
        {
            Console.WriteLine($"Баланс: {Balance:F2} руб.");
        }
    }

    class Program
{
    static void Main()
    {
        BankAccount account = new BankAccount();
        Console.WriteLine($"Создан счёт: {account.AccountNumber}");

        while (true)
        {
            Console.WriteLine("\nВыберите действие:");
            Console.WriteLine("1 - Пополнить");
            Console.WriteLine("2 - Снять");
            Console.WriteLine("3 - Показать баланс");
            Console.WriteLine("0 - Выход");
            Console.Write("Ваш выбор: ");

            string choice = Console.ReadLine();

            if (choice == "0")
                break;

            //Условия выбора пользователя
            try
            {
                if (choice == "1" || choice == "2")
                {
                    Console.Write("Введите сумму: ");
                    string amountStr = Console.ReadLine();
                    decimal amount = Convert.ToDecimal(amountStr);

                    if (choice == "1")
                    {
                        account.Deposit(amount);
                        Console.WriteLine("Пополнение выполнено");
                    }
                    else if (choice == "2")
                    {
                        account.Withdraw(amount);
                        Console.WriteLine("Снятие выполнено");
                    }
                }
                else if (choice == "3")
                {
                }
                else
                {
                    Console.WriteLine("Неверный выбор! ");
                }
            }
            catch (InvalidAmountException ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }
            catch (InsufficientFundsException ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }
            catch (Exception)
            {
                Console.WriteLine("Ошибка: введите корректное число");
            }

            Console.WriteLine();
            account.ShowBalance();  //вывод баланса
        }
    }
}
}