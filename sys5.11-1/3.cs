using System;
using System.Diagnostics;
using System.Threading;

class Program
{
    static void Main()
    {
        //параметры запуска дочернего процесса
        var info = new ProcessStartInfo
        {
            FileName = "notepad.exe",
            Arguments = "timeout /t 60",
        };

        try
        {
            using (var child = Process.Start(info))
            {
                Process.Start("notepad.exe");
                Console.WriteLine("процесс запущен, ждём 3 секунды");

                if (child.WaitForExit(3000))
                {
                    Console.WriteLine("процесс завершился");
                }
                else
                {
                    Console.WriteLine("за 3 секунды не закрылся, убиваем");

                    child.Kill();
                    child.WaitForExit();
                    Console.WriteLine("процесс завершён");
                }
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"ошибка при работе с процессом: {ex.Message}");
        }
    }
}